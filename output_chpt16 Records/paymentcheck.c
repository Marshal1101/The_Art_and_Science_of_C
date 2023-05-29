/**
 * @file paymentcheck.c
 * @brief exercise 16-1
 * @date 2023-05-28
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "genlib.h"
#include "strlib.h"
#include "simpio.h"

/* Constant */
#define MaxEmployees        100
#define TaxDeduction        1
#define TaxRate             0.25
#define CheckWidth          52
#define MaxWord             25
#define MaxControlString    50

/* Data structures */
typedef struct
{
    string name;
    string title;
    string ssnum;
    double salary;
    int withholding;
} *employeeT;


typedef struct {
    string dbtitle;
    employeeT staff[MaxEmployees + 1];
    int nEmployees;
} *employeeDB;

/* Prototype Funcions */
static void PrintWeeklyPaycheck(employeeDB db);
static void PrintOnePaycheck(employeeT emp);
static void PrintInnerBlank(void);
static void PrintBrokenLine(void);
static employeeDB ReadEmployeeDatabase(void);
static employeeT ReadOneEmployee(FILE *infile, employeeDB db);
static FILE *OpenUserFile(string prompt, string mode);

int main(void)
{
    employeeDB employee;

    employee = ReadEmployeeDatabase();      // emp.dat
    PrintWeeklyPaycheck(employee);
}

static void PrintWeeklyPaycheck(employeeDB db)
{
    int i;

    for (i = 0; i < db->nEmployees; i++) {
        PrintOnePaycheck(db->staff[i]);
    }
}

static void PrintOnePaycheck(employeeT emp)
{
    double tax, pay;
    string corp, calcbuf, ceo;
    int w, len;

    tax = TaxRate * (emp->salary - (emp->withholding * TaxDeduction));
    pay = emp->salary - tax;

    corp = "Scrooge and Marley Ltd";
    ceo ="E. Scrooge";
    calcbuf = (string) GetBlock(MaxWord);
    sprintf(calcbuf, "%.2lf gross - %.2lf tax", emp->salary, tax);
    len = StringLength(corp);
    PrintBrokenLine();
    printf("| %-50s |\n", corp);
    PrintInnerBlank();
    printf("| Pay to the order of: %-20s%7.2lf   |\n", emp->name, pay);
    PrintInnerBlank();
    PrintInnerBlank();
    printf("| %-30s%20s |\n", calcbuf, ceo);
    PrintBrokenLine();
}

void PrintInnerBlank(void) {
    int w;

    w = 0;
    putchar('|');
    while (w++ < CheckWidth) putchar(' ');
    putchar('|');
    printf("\n");
}

void PrintBrokenLine(void) {
    int w;

    w = 0;
    putchar('+');
    while (w++ < CheckWidth) putchar('-');
    putchar('+');
    printf("\n");
}

employeeDB ReadEmployeeDatabase(void)
{
    FILE *infile;
    employeeDB db;
    employeeT empptr;
    int nEmplyees;

    infile = OpenUserFile("Enter db file name: ", "r");
    db = New(employeeDB);
    db->dbtitle = ReadLine(infile);
    nEmplyees = 0;
    while (nEmplyees < MaxEmployees && (empptr = ReadOneEmployee(infile, db))) {
        db->staff[nEmplyees] = empptr;
        nEmplyees++;
    };
    db->staff[nEmplyees] = NULL;
    db->nEmployees = nEmplyees;
    fclose(infile);
    return (db);
}

static employeeT ReadOneEmployee(FILE *infile, employeeDB db)
{
    employeeT emp;
    string line, name1, name2, title, ssnum, namebuf;
    double salary;
    int nscan, withholding;

    line = ReadLine(infile);
    if (line == NULL) return (NULL);
    emp = New(employeeT);
    name1 = (string) GetBlock(MaxWord);
    name2 = (string) GetBlock(MaxWord);
    title = (string) GetBlock(MaxWord);
    ssnum = (string) GetBlock(MaxWord);
    nscan = sscanf(line, "%s %s %s %s %lf %d%c", 
                    name1, name2, title, ssnum, &salary, &withholding);
    if (nscan != 6) {
        printf("nscan(%d) fail: %s,1 %s,2 %s,3 %s,4 %lf,5 %d,6 %d\n",
                nscan, name1, name2, title, ssnum, salary, withholding);
        Error("ReadOneEmployee:nscan:Improper file format");
    }
    // printf("suc: %s %s %s %lf %d%c", name, title, ssnum, salary, withholding);
    namebuf = (string) GetBlock(MaxWord);
    sprintf(namebuf, "%s %s", name1, name2);
    emp->name = namebuf;
    emp->title = title;
    emp->ssnum = ssnum;
    emp->salary = salary;
    emp->withholding = withholding;
    return (emp);
}


FILE *OpenUserFile(string prompt, string mode)
{
    FILE *result;
    string filename;

    while (TRUE) {
        printf("%s", prompt);
        filename = GetLine();
        result = fopen(filename, mode);
        if (result != NULL) break;
        printf("File %s not found -- try again.\n", filename);
    }
    return (result);
}
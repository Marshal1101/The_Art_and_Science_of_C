/**
 * @file librarydatabase.c
 * @brief exercie 16-2
 * @date 2023-05-29
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "genlib.h"
#include "strlib.h"
#include "simpio.h"
#include "scanner.h"

#define MaxBookElements         1000
#define MaxAddElements          5
#define MaxWord                 24
#define Split                   ","

typedef struct {
    string title;
    string *writers;
    string catalogno;
    string *subjects;
    string publisher;
    int pubyear;
    string isPossibleLoan;
} *bookT;

typedef struct {
    bookT booklist[MaxBookElements];
    int nElements;
} *libraryDB;


static libraryDB ReadLibraryDatabase(void);
static bookT ReadOneBook(FILE *infile, libraryDB db);
static void ScanBookFromLine(bookT book, string line);
static string *GetArrayFromString(string buf, char splitch);
static void SearchBySubject(libraryDB db, string sub);
static FILE *OpenUserFile(string prompt, string mode);

int main(void)
{
    libraryDB libdata;
    string subject;

    libdata = ReadLibraryDatabase();
    printf("subject: ");
    subject = GetLine();
    SearchBySubject(libdata, subject);
    return 0;
}

static libraryDB ReadLibraryDatabase(void)
{
    FILE *infile;
    libraryDB db;
    bookT book;
    int nElements;

    infile = OpenUserFile("Input file: ", "r");
    db = New(libraryDB);
    nElements = 0;
    while (book = ReadOneBook(infile, db)) {
        if (nElements == MaxBookElements) Error("nElements:bookdata oversize, %d", MaxBookElements);
        db->booklist[nElements] = book;
        nElements++;
    }
    db->booklist[nElements] = NULL;
    db->nElements = nElements;
    return (db);
}

static bookT ReadOneBook(FILE *infile, libraryDB db)
{
    bookT book;
    string line;

    line = ReadLine(infile);
    if (line == NULL) return (FALSE);
    book = New(bookT);
    ScanBookFromLine(book, line);
    return book;
}

static void ScanBookFromLine(bookT book, string line)
{
    string title, catalogno, publisher, isPossibleLoan, sformat;
    string writersbuf, subjectsbuf;
    int pubyear, nscan;

    title = NewArray(MaxWord+1, char);
    writersbuf = NewArray(MaxWord * MaxAddElements, char);
    catalogno = NewArray(MaxWord+1, char);
    subjectsbuf = NewArray(MaxWord * MaxAddElements, char);
    publisher = NewArray(MaxWord+1, char);
    isPossibleLoan = NewArray(MaxWord+1, char);

    sformat = NewArray(MaxWord * 10, char);
    sprintf(sformat, "%%24[^%s]%s%%120[^%s]%s%%24[^%s]%s%%120[^%s]%s%%24[^%s]%s%%d%s%%s",
            Split, Split, Split, Split, Split, Split, Split, Split, Split, Split, Split);
    // printf("sf: %s\n", sformat);
    nscan = sscanf(line, sformat,
            title, writersbuf, catalogno, subjectsbuf, publisher, &pubyear, isPossibleLoan);
    if (nscan != 7) {
        printf("nscan=%d, 1-%s-2-%s-3-%s-4-%s-5-%s-6-%d-7-%s\n",
                nscan, title, writersbuf, catalogno, subjectsbuf, publisher, pubyear, isPossibleLoan);
        Error("ScanBookFromLine:nscan=%d, %s %s %s %s %s %d %s\n",
                nscan, title, writersbuf, catalogno, subjectsbuf, publisher, pubyear, isPossibleLoan);
    }
    book->title = title;
    book->writers = GetArrayFromString(writersbuf, '/');
    book->catalogno = catalogno;
    book->subjects = GetArrayFromString(subjectsbuf, '/');
    book->publisher = publisher;
    book->pubyear = pubyear;
    book->isPossibleLoan = isPossibleLoan;
    printf("nscan=%d, %s %s %s %s %s %d %s\n",
            nscan, book->title, book->writers[0], book->catalogno, book->subjects[1], book->publisher, book->pubyear, book->isPossibleLoan);
}

static string *GetArrayFromString(string buf, char splitch)
{
    string *arr;
    int n, st, idx;

    arr = NewArray(MaxAddElements, string);
    n = st = 0;
    while ((idx = FindChar(splitch, buf, st)) > 0) {
        arr[n++] = SubString(buf, st, idx-1);
        st = idx + 1;
    }
    if (n == 0) {
        FreeBlock(arr);
        return (NULL);
    }
    if (st != 0) arr[n++] = SubString(buf, st, StringLength(buf)-1);
    arr[n] = NULL;
    return (arr);
}


static void SearchBySubject(libraryDB db, string sub)
{
    bookT book;
    string *subject;
    int i, j;

    for (i = 0; i < db->nElements; i++) {
        book = db->booklist[i];
        subject = book->subjects;
        for (j = 0; subject[j]; j++) {
            if (StringEqual(subject[j], sub)) {
                printf("%s, %s, %s\n", book->title, book->writers[0], book->catalogno);
            }
        }
    }
}

static FILE *OpenUserFile(string prompt, string mode)
{
    FILE *result;
    string filename;

    while (TRUE) {
        printf("%s", prompt);
        filename = GetLine();
        result = fopen(filename, mode);
        if (result != NULL) break;
        printf("File %s not found -- try again\n", filename);
    }
    return (result);
}
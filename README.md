# Build Library File
```cmd
// path: ./include (at this)

gcc -c genlib.c random.c simpio.c strlib.c caltools.c scanner.c labelseq.c fill.c hist.c sort.c myalloc.c readfile.c rational.c queue.c
ar r libmy.a genlib.o random.o simpio.o strlib.o caltools.o scanner.o labelseq.o fill.o hist.o sort.o myalloc.o readfile.o rational.o queue.o
ar s libmy.a
```

# Build Execution File
```cmd
gcc -o [newName] [filename.c] -lmy -Linclude -Iinclude
```

    #### -l : 임의 라이브러리 사용. 라이브러리 이름형식은 libxxx.a 인데, 여기서 xxx와 합쳐 -lxxx 를 입력합니다.
    #### -L : 임의 라이브러리가 위치한 디렉토리(폴더) 이름
    #### -I : 참조할 헤더가 컴파일할 c파일의 하위경로 xxx에 있을 경우, -Ixxx

# GDB Debugger Usage
_GDB 디버거 : 리눅스에서 가장 대표적인 디버거이다.(GNU debugger)_

주요 기능 : 정지점 설정, 한 줄씩 실행, 변수 접근 및 수정, 함수 탐색, 추적(tracing)

먼저 디버깅 전에 -g 옵션으로 컴파일​을 해야 한다.

```cmd
$ gcc -g -o longest longest.c 
$ gcc -g -o main main.c copy.c
```
​
그 후에 실행파일을 디버깅 모드로 실행한다.

```cmd
$ gdb [실행파일]
```
## gdb의 기능
----
1. 소스 보기 : l(ist)

    - l [줄번호] : 지정된 줄을 프린트한다.
    - l [파일명]:[함수명] : 지정된 함수를 프린트한다.
    - set listsize n : 출력되는 줄 수를 n 개로 변경한다.

2. 정지점 설정 : b(reak), clear, d(elete)

    - b [에서 n개 줄 이후에 정지점을 설정한다.
    - b -n : 현재 줄에서 n개 줄 이전에 정지점을 설정한다.
    - info b : 현재 설정된 정지점을 출력한다.
    - clear 줄번호 : 해당 정지점을 삭제한다.
    - b [파일]:[함수] : 함수의 시작부분에 - 정지점을 설정한다.
    - b n : n번 줄에 정지점을 설정한다.
    - b +n : 현재 줄
    - d : 모든 정지점을 삭제한다.

3. 프로그램 수행

    - r(un) 인수 : 명령줄 인수를 받아 프로그램 수행
    - k(ill) : 프로그램 수행 강제 종료
    - n(ext) : 멈춘 지점에서 다음 줄만 수행하고 멈춤
    - s(tep) : n과 동일. 함수호출 시 함수 내부로 진입
    - c(ontinue) : 정지점을 만날 때까지 수행
    - u : 반복문을 빠져 나옴
    - finish : 현재 수행 중인 함수 끝으로 이동
    - return : 현재 수행 중인 함수를 빠져 나옴
    - quit : 종료
​
4. 변수 값 프린트 : p(rint)

    - p [변수명] : 해당 변수 값 프린트
    - p 파일명::[변수명] : 특정 파일의 전역변수 프린트
    - p [함수명]::[변수명] : 특정 함수의 정적 변수 프린트
    - info locals : 현재 상태의 지역변수 프린트
---------------
## 2023/5/9 ~ 2023/5/31 감사합니다.
---------------
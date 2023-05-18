# Build Library File
    path: ./include (at this)
    gcc -c genlib.c random.c simpio.c strlib.c caltools.c scanner.c labelseq.c fill.c
    ar r libmy.a genlib.o random.o simpio.o strlib.o caltools.o scanner.o labelseq.o fill.o
    ar s libmy.a

# Build Execution File
    gcc -o [newName] [filename.c] -lmy -Linclude -Iinclude

#### -l : 임의 라이브러리 사용. 라이브러리 이름형식은 libxxx.a 인데, 여기서 xxx와 합쳐 -lxxx 를 입력합니다.
#### -L : 임의 라이브러리가 위치한 디렉토리(폴더) 이름
#### -I : 참조할 헤더가 컴파일할 c파일의 하위경로 xxx에 있을 경우, -Ixxx
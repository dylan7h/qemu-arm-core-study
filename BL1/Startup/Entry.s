@   .global == extern keyword

@   Section 이름
@   .text               :   컴파일러가 만든 기계어가 위치하는 섹션
@   .rdata              :   읽기전용 Data
@   .data               :   초기화된 전역 변수
@   .bss                :   초기화되지 않은 전역 변수
@   .symtab             :   Symbol Table - 전역 변수와 함수에 대한 Symbol을 저장.
@                           Linker가 rel.text와 rel.data에 있는 Symbol 정보와 
@                           이 섹션에 있는 Symbol 정보를 연결해서 Memory Offset을 지정.
@   .reltext, rel.data  :   다른 파일에 선언된 전역 변수나 함수를 호출할 때 컴파일러는 
@                           해당 심벌을 찾을 수 없으므로 일단 비워두고 이 섹션에 정보를 기록.
@   .debug              :   Debug Symbol 저장.( -g 옵션 사용시 )
@   .line               :   Debug Symbol의 Line 번호 저장.( -g 옵션 사용시 )
@   .strtab             :   파일 전체에 사용되는 문자열 정보가 이 섹션에 기록.

.text                       @   .text 섹션 시작
    .code 32                @   명령어 크기: 32bit

    .global vector_start    @   extern vector_start;
    .global vector_end      @   extern vector_end;

    vector_start:           @   vector_start 레이블 선언
        MOV R0, R1          @   R0 = R1;
    vector_end:             @   vector_end 레이블 선언
        .space 1024, 0      @   현재 Address 부터 1024 byte를 0으로 채워라.
.end                        @   .text 섹션 끝

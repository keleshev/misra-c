#include <stdio.h>
#define p printf

int b[] = { '0', '1', '2', '3' };

buf(int c) 
{
    int _b[] = { c, b[0], b[1], b[2] };

    for(int i=0; i<4; i++) {
        b[i] = _b[i];
    }
}

int in_comment_old;
int in_comment = 0;
inside_comment(int a[])
{
    in_comment_old = in_comment;
    
    if (a[1]=='/' && a[0]=='*')
        in_comment++;
        
    if (a[2]!='/' && a[1]=='*' && a[0]=='/')
        in_comment = 0;
}

rule_nested_comments(int in_comment, int in_comment_old, int line)
{
    if ( in_comment>=2 && in_comment_old!=in_comment )
        p("line %d: rule_nested_comments() violated \n", line);
    //p("(%d,%d)", in_comment, in_comment_old);
}

main()
{
    int c, line=1;
    
    while ((c = getchar()) != EOF) {
        if (c=='\n') line++;
        buf(c);
        inside_comment(b);
        
        rule_nested_comments(in_comment, in_comment_old, line);
    }
}

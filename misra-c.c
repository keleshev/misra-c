#include <stdio.h>

int b[] = { '0', '1', '2', '3' };
void /*b[]*/ buf(int c) {
    int _b[] = { c, b[0], b[1], b[2] };

    for(int i=0; i<4; i++) {
        b[i] = _b[i];
    }
}

int /*in_quote*/ check_if_in_quote(char quote_type, int in_quote, int a[]) {
    if (a[0]==quote_type) return !in_quote; 
    else return in_quote;
}

int /*in_comment*/ check_if_in_comment(int in_comment, int a[]) {
    if (a[1]=='/' && a[0]=='*')
        in_comment++;
    else
    if (a[2]!='/' && a[1]=='*' && a[0]=='/')
        in_comment = 0;
    
    return in_comment;
}

void rule_2_6_nested_comments(int in_comment, int in_comment_old, int line) {
    if ( in_comment>=2 && in_comment_old!=in_comment )
        printf("line %d: rule_2_6_nested_comments() violated \n", line);
}

int main() {
    char c;
    int line=1;
    int in_single_quote = 0;
    int in_double_quote = 0;
    int in_comment = 0;
    int in_comment_old;
    
    while ((c = getchar()) != EOF) {
        if (c=='\n') line++;
        buf(c);
        
        in_single_quote = check_if_in_quote('\'', in_single_quote, b);
        in_double_quote = check_if_in_quote('"',  in_double_quote, b);
        
        in_comment_old = in_comment;
        in_comment = check_if_in_comment(in_comment, b);
        
        rule_2_6_nested_comments(in_comment, in_comment_old, line);
        printf("%c",c);
    }
}

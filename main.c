#include <stdio.h>

#include "properties.c"
#include "rules.c"

int b[] = { '0', '1', '2', '3' };
void /*b[]*/ buf(int c) {
    int _b[] = { c, b[0], b[1], b[2] };
    
    for(int i=0; i<4; i++) {
        b[i] = _b[i];
    }
}

int main() {
    char c;
    int line = 1;
    int in_single_quote_old, in_single_quote = 0;
    int in_double_quote_old, in_double_quote = 0;
    int in_comment_old_old, in_comment_old, in_comment = 0;
    int in_code_old, in_code = 0;
    
    while ((c = getchar()) != EOF) {
        if (c=='\n') line++;
        buf(c);
        printf("%c",c);
         
        in_single_quote_old = in_single_quote;
        in_double_quote_old = in_double_quote;
        in_comment_old_old = in_comment_old;
        in_comment_old = in_comment;
        in_code_old = in_code;
        
        //
        // properties checks:
        //

        in_comment = check_if_in_comment(in_comment_old, 
                                         in_comment_old_old,
                                         in_single_quote_old,
                                         in_double_quote_old, b);
                                               
        in_single_quote = check_if_in_quote('\'', 
                                            in_single_quote_old, 
                                            in_double_quote_old,
                                            in_comment_old, b);
                                            
        in_double_quote = check_if_in_quote('"',
                                            in_double_quote_old, 
                                            in_single_quote_old,
                                            in_comment_old, b);
        
        in_code = check_if_in_code(in_comment_old,
                                   in_single_quote,
                                   in_double_quote);
        
        //
        // rules check:
        //
        
        rule_2_3_nested_comments_not_allowed(in_comment, in_comment_old, line);
        
    }
}

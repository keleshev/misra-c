#include <stdio.h>
#include <iso646.h>

#define DIGITS   "0123456789"
#define LETTERS  "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

#define IDENTIFIER_CHARACTERS        LETTERS "_" DIGITS 
#define IDENTIFIER_FIRST_CHARACTERS  LETTERS "_"

#include "properties.c"
#include "rules.c"

//char DIGITS[] = "0123456789";

int b[64] = { 0 };
void /*b[]*/ buf(int c) {
    int b_old[64] = { 0 };  //= { c, b[0], b[1], b[2] };
    
    for (int i=0; i<64; i++) b_old[i] = b[i];
    
    b[0] = c;
    
    for (int i=1; i<64; i++) {
        b[i] = b_old[i-1]; //printf("%c",b[i]);
    }
}

int main() {
    char c;
    int line = 1;
    int in_single_quote_old, in_single_quote = 0;
    int in_double_quote_old, in_double_quote = 0;
    int in_quote_old,        in_quote = 0;
    int in_comment_old_old, in_comment_old, in_comment = 0;
    int in_code_old, in_code = 0;
    int in_preprocessor_directive_old, in_preprocessor_directive = 0;
    
    while (c = getchar(), c != EOF) {
        if (c=='\n') line++;
        buf(c);
        printf("%c",c);
        //printf("%s \n",b);
         
        in_single_quote_old = in_single_quote;
        in_double_quote_old = in_double_quote;
        in_quote_old = in_quote;
        in_comment_old_old = in_comment_old;
        in_comment_old = in_comment;
        in_code_old = in_code;
        in_preprocessor_directive_old = in_preprocessor_directive;
        
        //
        // properties checks:
        //

        in_comment = check_if_in_comment(in_comment_old, 
                                         in_comment_old_old,
                                         in_single_quote_old,
                                         in_double_quote_old, b);
                                               
        in_single_quote = check_if_in_a_certain_quote('\'', 
                                                      in_single_quote_old, 
                                                      in_double_quote_old,
                                                      in_comment_old, b);
                                            
        in_double_quote = check_if_in_a_certain_quote('"',
                                                      in_double_quote_old, 
                                                      in_single_quote_old,
                                                      in_comment_old, b);
        
        in_quote = check_if_in_quote(in_single_quote_old,
                                     in_double_quote_old);
        
        in_code = check_if_in_code(in_comment_old,
                                   in_single_quote,
                                   in_double_quote);
        
        in_preprocessor_directive = check_if_in_preprocessor_directive(in_code,
                                              in_preprocessor_directive_old, b);
        
//        if (in_preprocessor_directive) printf("_");
//        if (in_single_quote) printf("'");
//        if (in_double_quote) printf("\"");
//        if (in_comment)      printf("_");
        
        //
        // rules check:
        //
        rule_2_2_cpp_style_comments_not_allowed(in_code, 
                                                b, line); 
        
        
        rule_2_3_nested_comments_not_allowed(in_comment, 
                                             in_comment_old, 
                                             line);
        
        rule_4_1_only_simple_escape_sequences_allowed(in_quote, 
                                                      b, line);
        
        rule_4_2_trigraphs_not_allowed(b, line);
        
        rule_5_1_identifiers_longer_than_31_characters_not_allowed(in_code,
                                                                   b, line);
                                                                   
        rule_7_1_octal_constants_and_escape_sequences_not_allowed(in_code,
                                                                  in_quote, 
                                                                  b, line);
                                                                   
        rule_14_4_goto_not_allowed(in_code, b, line);
        
        rule_14_5_continue_not_allowed(in_code, b, line);
        
        rule_19_6_undef_not_allowed(in_code, b, line);
        
        rule_19_13_token_concatenation_not_allowed(in_preprocessor_directive,
                                                   b, line);
        
    }
}











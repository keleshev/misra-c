#include <stdio.h>


void rule_2_2_cpp_style_comments_not_allowed(int in_code, 
                                             int a[],
                                             int line) 
{
    if (in_code and a[1]=='/' and a[0]=='/')
        printf("%d:rule_2_2_cpp_style_comments_not_allowed()\n", line);
}


void rule_2_3_nested_comments_not_allowed(int in_comment, 
                                          int in_comment_old, 
                                          int line) 
{
    if (in_comment>=2 and in_comment_old!=in_comment)
       printf("%d:rule_2_3_nested_comments_not_allowed()\n", line);
}


void rule_4_1_only_simple_escape_sequences_allowed(int in_quote,
                                                   int a[],
                                                   int line) 
{
    char simple_escape_sequences[] = "\'\"\\?abfnrtv0\n";
    
    if (in_quote 
        and a[3]!='\\' 
        and a[2]=='\\'
        and is_not_one_of(a[1], simple_escape_sequences))
        //and (a[1]!='0' or (a[1]=='0' and is_one_of(a[0],DIGITS))))
        printf("%d:rule_4_1_only_simple_escape_sequences_allowed()\n", line);
}


void rule_4_2_trigraphs_not_allowed(int a[], int line)
{
    // Trigraphs are: ??=  ??(  ??/  ??)  ??'  ??<  ??!  ??>  ??- 
    
    char trigraph_last_characters[] = "=()/'<!>-";
    
    if (a[2]=='?' and a[1]=='?' and is_one_of(a[0], trigraph_last_characters))
        printf("%d:rule_4_2_trigraphs_not_allowed()\n", line);
}


void rule_5_1_identifiers_longer_than_31_characters_not_allowed(int in_code,
                                                                int a[],
                                                                int line)
{   
    int n=1;
    
    if (in_code 
        and is_not_one_of(a[32], IDENTIFIER_CHARACTERS)
        and is_one_of(a[31], IDENTIFIER_FIRST_CHARACTERS))
            for (int i=0; i<31; i++)
                if (is_one_of(a[i], IDENTIFIER_CHARACTERS)) 
                    n++;
                    
    if (n==32)
       printf("%d:rule_5_1_identifiers_longer_than_31_characters_not_allowed\n",
              line);
}


void rule_7_1_octal_constants_and_escape_sequences_not_allowed(int in_code,
                                                               int in_quote,
                                                               int a[],
                                                               int line) 
{
    // Octal constants not allowed check:
    if (in_code
        and is_not_one_of(a[2], IDENTIFIER_CHARACTERS)
        and a[1]=='0'
        and is_one_of(a[0], DIGITS))
        printf("%d:rule_7_1_octal_constants_and_escape_sequences_not_allowed\n",
               line);
    
    // Octal escape sequences not allowed check:
    if (in_quote 
        and a[3]!='\\' 
        and a[2]=='\\'
        and a[1]=='0' 
        and is_one_of(a[0], DIGITS))
        printf("%d:rule_7_1_octal_constants_and_escape_sequences_not_allowed\n",
               line);
}


void rule_14_4_goto_not_allowed(int in_code, int a[], int line)
{
    if (in_code
        and is_not_one_of(a[5], IDENTIFIER_CHARACTERS)
        and is_in_buffer_at("goto", a, 4)
        and is_not_one_of(a[0], IDENTIFIER_CHARACTERS))
            printf("%d:rule_14_4_goto_not_allowed()\n", line);
}


void rule_14_5_continue_not_allowed(int in_code, int a[], int line)
{
    if (in_code
        and is_not_one_of(a[9], IDENTIFIER_CHARACTERS)
        and is_in_buffer_at("continue", a, 8)
        and is_not_one_of(a[0], IDENTIFIER_CHARACTERS))
            printf("%d:rule_14_5_continue_not_allowed()\n", line);
}


void rule_19_6_undef_not_allowed(int in_code, int a[], int line)
{
    if (in_code
        and is_not_one_of(a[7], IDENTIFIER_CHARACTERS)
        and is_in_buffer_at("#undef", a, 6)
        and is_not_one_of(a[0], IDENTIFIER_CHARACTERS))
            printf("%d:rule_19_6_undef_not_allowed()\n", line);
}


void rule_19_13_token_concatenation_not_allowed(int in_preprocessor_directive,
                                                int a[], int line)
{
    if (in_preprocessor_directive and a[0]=='#')
        printf("%d:rule_19_13_token_concatenation_not_allowed()\n", line);
}











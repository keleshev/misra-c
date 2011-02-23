#include <stdio.h>


void rule_2_2_cpp_style_comments_not_allowed(int in_code, 
                                             int a[],
                                             int line) 
{
    if (in_code and a[1]=='/' and a[0]=='/')
        printf("%d: rule_2_2_cpp_style_comments_not_allowed()\n", line);
}

void rule_2_3_nested_comments_not_allowed(int in_comment, 
                                          int in_comment_old, 
                                          int line) 
{
    if (in_comment>=2 and in_comment_old!=in_comment)
       printf("%d: rule_2_3_nested_comments_not_allowed()\n", line);
}

void rule_4_2_only_simple_escape_sequences_allowed(int in_quote,
                                                   int a[],
                                                   int line) 
//{
//    char simple_escape_sequences[] = "\'\"\\?abfnrtv";
    
//    if (in_quote and a[3]!='\\' and a[2]=='\\') 
//        if (not is_one_of(a[1], simple_escape_sequences))
//            if (a[1]!='0' or (a[1]=='0' and is_one_of(a[0],DIGITS)))
//                printf("%d: rule_4_2_only_simple_escape_sequences_allowed()\n", 
//                       line);
//}
{
    char simple_escape_sequences[] = "\'\"\\?abfnrtv";
    
    if (in_quote 
        and a[3]!='\\' 
        and a[2]=='\\'
        and not is_one_of(a[1], simple_escape_sequences)
        and (a[1]!='0' or (a[1]=='0' and is_one_of(a[0],DIGITS)))
        printf("%d: rule_4_2_only_simple_escape_sequences_allowed()\n", line);
}


#include <stdio.h>

void rule_2_3_nested_comments_not_allowed(int in_comment, 
                                          int in_comment_old, 
                                          int line) 
{
    if ( in_comment>=2 && in_comment_old!=in_comment )
       printf("%d: rule_2_3_nested_comments_not_allowed() violated \n", line);
}


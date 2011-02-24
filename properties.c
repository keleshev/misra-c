#include <stdio.h>


int /*is_one_of_{kind}*/ is_one_of(char character, char string[])
{
    char c;
    int i=0;
    
    while(c = string[i++], c != '\0')
        if (character == c) return 1;
        
    return 0;
}


int /*is_not_one_of_{kind}*/ is_not_one_of(char character, char string[])
{
    return not is_one_of(character, string);
}


int /*is_in_buffer_at_{position}*/ is_in_buffer_at(char string[],
                                                    int buffer[],
                                                    int position)
{
    char c1, c2;
    int i1=0, i2=position;
    
    while(c1=string[i1++], 
          c2=buffer[i2--],
          c1!='\0' or c1!='\0')
        if (c1 != c2) return 0;
        //printf("<%c=%c>",c1,c2);

    return 1;
}


int /*in_{quote_type}_quote*/ check_if_in_a_certain_quote(char quote_type, 
                                                int in_a_certain_quote_old, 
                                                int in_other_type_of_quote_old,
                                                int in_comment_old,
                                                int a[]) 
{   
    int in_a_certain_quote;
    
    if (in_comment_old!=0                   // If we are inside of comment,
        or in_other_type_of_quote_old==1 )  // or another kind of quote (' or ")
        in_a_certain_quote = 0;             // then it's not our quote anyway.
    
    else if (a[0]==quote_type)   // If we encounter our quote in buffer,
                                 // it is either a closing or opening quote,
                                 // so we change the state to the opposit:
        in_a_certain_quote = !in_a_certain_quote_old;  
    
    // Otherwise change nothing:
    else in_a_certain_quote = in_a_certain_quote_old;
    
    return in_a_certain_quote;
}


int /*in_comment*/ check_if_in_comment(int in_comment_old, 
                                       int in_comment_old_old, 
                                       int in_single_quote_old,
                                       int in_double_quote_old,
                                       int a[]) 
{
    int in_comment;
    
    if (in_single_quote_old==1      // If we are in either
        or in_double_quote_old==1)  // type of quote (' or "),
        in_comment = 0;             // it's not a comment.
    
    else if (a[1]=='/' and a[0]=='*')  // If we encounter /* in buffer,
        in_comment = in_comment_old + 1;  // a comment had started 
                                    // (maybe nested comment).
    
    else if (a[1]=='*' and a[0]=='/'  // If we encounter */ in buffer,
                  and in_comment_old_old!=0)  // and we are inside a comment,
        in_comment = 0;                  // then we just closed this comment.
    else
        in_comment = in_comment_old;
    
    return in_comment;
}


int /*in_quote*/ check_if_in_quote(int in_single_quote,
                                   int in_double_quote)
{
    if (in_single_quote or in_double_quote) return 1;
    else return 0;
}


int /*in_code*/ check_if_in_code(int in_comment,
                                 int in_single_quote,
                                 int in_double_quote)
{
    if (in_comment or in_single_quote or in_double_quote) return 0;
    else return 1;
}

int check_if_in_preprocessor_directive(int in_code,
                                       int in_preprocessor_directive,
                                       int a[])
{
    if (in_code and not in_preprocessor_directive and a[0]=='#')
        return 1;
    else if (in_code and in_preprocessor_directive 
             and a[0]=='\n' and a[1]!='\\')
        return 0;
    else return in_preprocessor_directive;
}






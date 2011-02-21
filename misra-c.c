#include <stdio.h>

int b[] = { '0', '1', '2', '3' };
void /*b[]*/ buf(int c) {
    int _b[] = { c, b[0], b[1], b[2] };
    
    for(int i=0; i<4; i++) {
        b[i] = _b[i];
    }
}


int /*in_quote*/ check_if_in_quote(char quote_type, 
                                    int in_quote_old, 
                                    int in_other_type_of_quote_old,
                                    int in_comment_old,
                                    int a[]) 
{   
    int in_quote;
    
    if (in_comment_old!=0                   // If we are inside of comment,
        || in_other_type_of_quote_old==1 )  // or another kind of quote (' or ")
        in_quote = 0;                       // then it's not our quote anyway.
    
    else if (a[0]==quote_type)   // If we encounter our quote in buffer,
                                   // it is either a closing or opening quote,
        in_quote = !in_quote_old;  // so we change the state to the opposit.
    
    else in_quote = in_quote_old;   // Otherwise change nothing.
    
    if (in_quote) printf("%c",quote_type);
    
    return in_quote;
}

int /*in_comment*/ check_if_in_comment(int in_comment_old, 
                                       int in_comment_old_old, 
                                       int in_single_quote_old,
                                       int in_double_quote_old,
                                       int a[]) 
{
    int in_comment;
    
    if (in_single_quote_old==1      // If we are in either
        || in_double_quote_old==1)  // type of quote (' or "),
        in_comment = 0;             // it's not a comment.
    
    else if (a[1]=='/' && a[0]=='*')  // If we encounter /* in buffer,
        in_comment = in_comment_old + 1;  // a comment had started 
                                    // (maybe nested comment).
    
    else if (a[1]=='*' && a[0]=='/'  // If we encounter */ in buffer,
                  && in_comment_old_old!=0)  // and we are inside a comment,
        in_comment = 0;                  // then we just closed this comment.
    else
        in_comment = in_comment_old;
    
    //if (in_comment) 
    //if (in_comment) 
    //printf("%d",in_comment);
    
    return in_comment;
}

void rule_2_3_nested_comments_not_allowed(int in_comment, 
                                          int in_comment_old, 
                                          int line) 
{
    if ( in_comment>=2 && in_comment_old!=in_comment )
       printf("%d: rule_2_3_nested_comments_not_allowed() violated \n", line);
}

int main() {
    char c;
    int line = 1;
    int in_single_quote_old, in_single_quote = 0;
    int in_double_quote_old, in_double_quote = 0;
    int in_comment_old_old, in_comment_old, in_comment = 0;
    
    while ((c = getchar()) != EOF) {
        if (c=='\n') line++;
        buf(c);
        
        // helper functions
         
        in_single_quote_old = in_single_quote;
        in_double_quote_old = in_double_quote;
        in_comment_old_old = in_comment_old;
        in_comment_old = in_comment;
        //printf("%d",in_comment);
        in_comment = check_if_in_comment(in_comment_old, 
                                         in_comment_old_old,
                                         in_single_quote_old,
                                         in_double_quote_old, b);
                                         
        //printf("%d",in_comment);
                                                 
        in_single_quote = check_if_in_quote('\'', 
                                            in_single_quote_old, 
                                            in_double_quote_old,
                                            in_comment_old, b);
                                            
        in_double_quote = check_if_in_quote('"',
                                            in_double_quote_old, 
                                            in_single_quote_old,
                                            in_comment_old, b);

        
        // rules
        
        rule_2_3_nested_comments_not_allowed(in_comment, in_comment_old, line);
        printf("%c",c);
    }
}

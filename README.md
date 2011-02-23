MISRA-C
=======

This project is an attempt to implement a small command-line tool for checking the conformance of programs written in C with some of the rulse of [MISRA-C:2004](http://en.wikipedia.org/wiki/MISRA_C) software development standard. 

The following rules are planned to be implemented
-------------------------------------------------

### Rule 2.2 (requited): Source code shall only use /* ... */ style comments.

### Rule 2.3 (required): The character sequence /* shall not be used within a comment.

### Rule 4.1 (required): Only those escape sequences that are defined in the ISO C standard shall be used.

Permited: 
    
        \'  \"  \?  \\  \a  \b  \f  \n  \r  \t  \v  \0

Not permited:

        \0... octal-digit
        \x... hexadecimal-digit 

### Rule 4.2 (required): Trigraphs shall not be used.

        ??=  ??(  ??/  ??)  ??'  ??<  ??!  ??>  ??- 

### Rule 5.1 (required): Identifiers (internal and external) shall not rely on the significance of more than 31 characters.

### Rule 7.1 (required): Octal constants (other than zero) and octal escape sequences shall not be used.

### Rule 12.10 (required): The comma operator shall not be used.

### Rule 12.13 (advisory): The increment (++) and decrement (--) operators should not be mixed with other operators in an expression.

### Rule 13.1 (required): Assignment operators shall not be used in expressions that yield a Boolean value.

i.e. in expressions like if(...) and while, or is it more complex?

### Rule 14.3 (required): Before preprocessing, a null statement shall only occur on a line by itself; it may be followed by a comment provided that the first character following the null statement is a white-space character.

### Rule 14.4 (required): The goto statement shall not be used.

### Rule 14.5 (required): The continue statement shall not be used.

### Rule 14.6 (required): For any iteration statement there shall be at most one break statement used for loop termination.

### Rule 14.7 (required): A function shall have a single point of exit at the end of the function.

### Rule 14.8 (required): The statement forming the body of a switch, while, do ... while or for statement shall be a compound statement.

### Rule 14.9 (required): An if (expression) construct shall be followed by a compound statement. The else keyword shall be followed by either a compound statement, or another if statement.

### Rule 14.10 (required): All if ... else if constructs shall be terminated with an else clause.

### Rule 15.3 (required): The final clause of a switch statement shall be the default clause.

### Rule 15.5 (required): Every switch statement shall have at least one case clause.

### Rule 19.1 (advisory): #include statements in a file should only be preceded by other preprocessor directives or comments.

### Rule 19.2 (advisory): Non-standard characters should not occur in header file names in #include directives.

### Rule 19.5 (required): Macros shall not be #define’d or #undef’d within a block.

### Rule 19.6 (required): #undef shall not be used.

### Rule 19.12 (required): There shall be at most one occurrence of the # or ## operators in a single macro definition.

### Rule 19.13 (advisory): The # and ## operators should not be used.







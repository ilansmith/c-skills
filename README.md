c-skills
========
Implement the function

  int check_brackets(char *text);

which checks whether brackets within 'text' are correctly nested. You need to
consider brackets of three kinds: (), [], {}.

A high emphasis must be put on simplicity and performance.

Examples:
- check_brackets("a(b)") -> true (CORRECT)
- check_brackets("[{}]") -> true (CORRECT)
- check_brackets("[(]") -> false (CORRECT)
- check_brackets("}{") -> false (CORRECT)
- check_brackets("z([{}-()]{a})") -> true (CORRECT)
- check_brackets("[{}a ] b") -> true (CORRECT)
- check_brackets("") -> true (CORRECT)


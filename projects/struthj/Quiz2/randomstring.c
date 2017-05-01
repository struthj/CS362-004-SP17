CS362 Quiz 2
Joseph Struth

To meet the testing requirements for this function, it requires inputChar
to randomly select a character that will meet each case after enough
iterations to expand the state. To reach the error edge case after
reaching state 9 it requires the string "reset" to be returned by the
inputString function. Note that with my implementation this may take
100,000+ iterations.
To solve this testing funciton in inputChar the ascii values of the
possible values ' ' to '}' are chosen using rand() and returned. This will
after enough iterations advance through the states until state 9 when the
inputString function returned string is tested. At state 9 the string
"reset" is checked for and will exit once it returns true. To implement
inputString I again used rand() with letters e through t to spell reset
given enough iterations.
Note that it may take between 100000-1000000+ iterations to reach the
error edge case.

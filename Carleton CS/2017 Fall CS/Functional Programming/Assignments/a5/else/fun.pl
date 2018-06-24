/*----------------------------------------------------------------------------
Author:   Robert Kyle Thompson                          Student #:    100880238
Course:   F17 COMP 3007 Programming Paradigms           Date:        2017.12.07
School:   Carleton University                           Due: 2017.12.07 at 2355
File:_    COMP3007_as5-100880238-Thom.pl             _       _  _   ____ Ver: 2   
    / \   ___ ___(_) __ _ _ __  _ __ ___   ___ _ __ | |_   _| || |_| ___| 
   / _ \ / __/ __| |/ _` | '_ \| '_ ` _ \ / _ \ '_ \| __| |_  ..  _|___ \ 
  / ___ \\__ \__ \ | (_| | | | | | | | | |  __/ | | | |_  |_      _|___) |
 /_/   \_\___/___/_|\__, |_| |_|_| |_| |_|\___|_| |_|\__|   |_||_| |____/ 
                    |___/         

Constraints: None.

Assumptions: None.

Citations:   [^1] Assignment questions are from Dr. Andrew Runka found at
      http://people.scs.carleton.ca/~arunka/courses/comp3007/assignments/a5/
             [^2] Programming in Prolog: Using the ISO Standard 5th Edition 
      by William F. Clocksin (Author),‎ Christopher S. Mellish (Author) 
----------------------------------------------------------------------------*/


%------------------------------- Question 1 ----------------------------------

% Establish a database of facts for the following 5 clauses:
% male(X) % X is male 
% female(X) % X is female 
% father(X,Y) %X is the father of Y
% mother(X,Y) %X is the mother of Y
% married(X,Y) %X is married to Y

% the house of windsor.

father(andrew,beatrice).
father(andrew,eugenie).
father(charles,henry).
father(charles,william).
father(edward,lousie).
father(edward,severn).
father(mark,peter).
father(mark,zara).
father(mike,mia).
father(peter,isla).
father(peter,savannah).
father(philip,andrew).
father(philip,anne).
father(philip,charles).
father(philip,edward).
father(william,charlotte).
father(william,george).
female(anne).
female(autumn).
female(beatrice).
female(catherine).
female(charlotte).
female(diana).
female(elizabeth). 
female(eugenie).
female(isla).
female(louise).
female(meghan).
female(mia).		
female(sarah).
female(savannah).
female(sophie).
female(zara).
male(andrew).
male(charles).
male(edward).
male(george).
male(henry).
male(roger). % not part of the family.
male(mark).
male(mike).
male(peter).
male(philip).      
male(severn).
male(william).
married(anne,mark).
married(autumn,peter).
married(catherine,william).
married(diana,charles).
married(elizabeth,philip).
married(henry,meghan).
married(sarah,andrew).
married(sophie,edward).
married(zara,mike).
mother(anne,peter).
mother(anne,zara).
mother(autumn,isla).
mother(autumn,savannah).
mother(catherine,charlotte).
mother(catherine,george).
mother(diana,henry).
mother(diana,william).
mother(elizabeth,andrew).
mother(elizabeth,anne).
mother(elizabeth,charles).
mother(elizabeth,edward).
mother(sarah,beatrice).
mother(sarah,eugenie).
mother(sophie,louise).
mother(sophie,severn).
mother(zara,mia).

% is_mother(X) is a mother
is_mother(X) :- 
	mother(X,_).

% is_father(X) X is a father
is_father(X) :- 
	father(X,_).

% parent(X,Y) X is the parent of Y
parent(X,Y) :- 
	mother(X,Y).
parent(X,Y) :- 
	father(X,Y).

% different(X,Y) X and Y are different
different(X,Y) :- 
	not(X=Y).

%sister(X,Y) X is a sister of Y
sister(X,Y) :- 
	parent(P,Y),
	parent(P,X),
	female(X), 
    different(X,Y).

% brother(X,Y) X is a brother of Y
brother(X,Y) :- 
	parent(P,Y),
    parent(P,X),
	male(X), 
    different(X,Y).

% this is not asked for in the question, but makes 
% finding aunts and uncles easier.
% sibling(X,Y) X and Y are siblings.
sibling(X,Y) :- 
	sister(X,Y).
sibling(X,Y) :- 
	brother(X,Y).
				
% aunt(X,Y) X is an aunt of Y (by blood)
aunt(X,Y):- 
	parent(P,Y),
    sister(X,P).

% aunt(X,Y) X is an aunt of Y (by marriage)
aunt(X,Y) :- 
	female(X),
    married(X,Z),  
    sibling(Z,W),
	parent(W,Y).
			 
% uncle(X,Y) X is an uncle of Y (by blood)
uncle(X,Y) :- 
	parent(P,Y),
    brother(X,P).

% uncle(X,Y) X is an uncle of Y (by marriage`)
uncle(X,Y) :- 
	male(X),
    married(X,Z),  
    sibling(Z,W),
	parent(W,Y).
			  
% grandfather(X,Y) X is a grandfather of Y
grandfather(X,Y) :- 
	parent(P,Y),
    father(X,P).
					
% grandmother(X,Y)  X is a grandmother of Y
grandmother(X,Y) :- 
	parent(P,Y),
    mother(X,P).

% ancestor(X,Y) X is an ancestor of Y
ancestor(X,Y) :- 
	parent(X,Y).
ancestor(X,Y) :- 
	parent(X,Z), 
    ancestor(Z,Y).

%------------------------------- Question 2 ----------------------------------
				  
actor(jonny, depp, gender(male)).
actor(bruce, willis, gender(male)).
actor(glenn, close, gender(female)).
actor(orlando, bloom, gender(male)).
actor(jennifer, lawrence, gender(female)).
actor(sean, bean, gender(male)).
actor(angelina, jolie, gender(female)).
actor(keira, knightley, gender(female)).
actor(benedict, cumberbatch, gender(male)).
actor(james,mcavoy, gender(male)).
actor(robin, williams, gender(male)).
actor(emilia, clarke, gender(female)).
actor(ryan, reynolds, gender(male)).
actor(chris, pratt, gender(male)).
actor(karen, gillan, gender(female)).

movie(year(2003), title([pirates,of,the,carribean]), cast([actor(jonny, depp),
      actor(keira, knightley), actor(orlando, bloom)])).
movie(year(2014), title([guardians, of, the, galaxy]), cast([actor(chris,
      pratt), actor(karen,gillan) ])).
movie(year(1988), title([die,hard]), cast([actor(bruce, willis)])).
movie(year(2001), title([lord,the,of,rings]), cast([actor(orlando, bloom), 
      actor(sean, bean)])).
movie(year(2016), title([xmen, apocalypse]), cast([actor(jennifer,lawrence), 
      actor(james, mcavoy)])).
movie(year(2014), title([the,imitation,game]), cast([actor(benedict, 
      cumberbatch), actor(keira, knightley)])).
movie(year(2012), title([the,hunger,games]), cast([actor(jennifer, 
      lawrence)])).
movie(year(2016), title([deadpool]), cast([actor(ryan, reynolds)])).

% [1 mark] What movies were released before 2010?
% movie(year(Y),title(T),_),Y < 2010.
% Y = 2003,
% T = [pirates, of, the, carribean] ;
% Y = 1988,
% T = [die, hard] ;
% Y = 2001,
% T = [lord, the, of, rings] ;

% [1 mark] What movies contain both the words "of" and "the" in the title
% movie(_,title(T),_), member(of, T), member(the, T).
% T = [pirates, of, the, carribean] ;
% T = [guardians, of, the, galaxy] ;
% T = [lord, the, of, rings] ;
% false.

% [2 marks] What movies share one or more common actor?
% movie(_,title(T1),cast(C1)), member(A1, C1), 
% movie(_, title(T2),cast(C2)), member(A2, C2), A1 = A2, not(T1 = T2).
% T1 = [pirates, of, the, carribean],
% C1 = [actor(jonny, depp), actor(keira, knightley), actor(orlando, bloom)],
% A1 = A2, A2 = actor(keira, knightley),
% T2 = [the, imitation, game],
% C2 = [actor(benedict, cumberbatch), actor(keira, knightley)] ;
% T1 = [pirates, of, the, carribean],
% C1 = [actor(jonny, depp), actor(keira, knightley), actor(orlando, bloom)],
% A1 = A2, A2 = actor(orlando, bloom),
% T2 = [lord, the, of, rings],
% C2 = [actor(orlando, bloom), actor(sean, bean)] ;
% T1 = [lord, the, of, rings],
% C1 = [actor(orlando, bloom), actor(sean, bean)],
% A1 = A2, A2 = actor(orlando, bloom),
% T2 = [pirates, of, the, carribean],
% C2 = [actor(jonny, depp), actor(keira, knightley), actor(orlando, bloom)] ;
% T1 = [xmen, apocalypse],
% C1 = [actor(jennifer, lawrence), actor(james, mcavoy)],
% A1 = A2, A2 = actor(jennifer, lawrence),
% T2 = [the, hunger, games],
% C2 = [actor(jennifer, lawrence)] ;
% T1 = [the, imitation, game],
% C1 = [actor(benedict, cumberbatch), actor(keira, knightley)],
% A1 = A2, A2 = actor(keira, knightley),
% T2 = [pirates, of, the, carribean],
% C2 = [actor(jonny, depp), actor(keira, knightley), actor(orlando, bloom)] ;
% T1 = [the, hunger, games],
% C1 = [actor(jennifer, lawrence)],
% A1 = A2, A2 = actor(jennifer, lawrence),
% T2 = [xmen, apocalypse],
% C2 = [actor(jennifer, lawrence), actor(james, mcavoy)] ;
% false.

% [2 mark] What movies star an actor with the first name "chris"?
% movie(_,title(T),cast(C)),member(actor(chris, _), C).
% T = [guardians, of, the, galaxy],
% C = [actor(chris, pratt), actor(karen, gillan)] ;
% false.

% [1 mark] What are the names of the female actors?
% actor(First,Last,gender(female)).
% First = glenn,
% Last = close ;
% First = jennifer,
% Last = lawrence ;
% First = angelina,
% Last = jolie ;
% First = keira,
% Last = knightley ;
% First = emilia,
% Last = clarke ;
% First = karen,
% Last = gillan.

% [2 marks] In what movies is Sean Bean a member of the cast?
% movie(_,title(T),cast(C)),member(actor(sean, bean), C).
%T = [lord, the, of, rings],
%C = [actor(orlando, bloom), actor(sean, bean)] ;
% false.

% [2 marks] What actors are in the cast of more than 1 movie?
% movie(_,title(T1),cast(C1)), member(A1, C1),movie(_, title(T2),cast(C2)), member(A2, C2), A1 = A2, not(T1 = T2).
%% TODO remove the movie titles.

% [2 marks] What is the title of the oldest movie?
% movie(year(Y1),title(T),_), not((movie(year(Y2),_,_),Y2<Y1)).
% Y1 = 1988,
% T = [die, hard] ;
% false.

% [2 marks] What actors are not in the cast of any movie?
% actor(F,L,_), not((movie(_,_,cast(C)), member(actor(F,L),C))).                                              %%TODO
% F = glenn,
% L = close ;
% F = angelina,
% L = jolie ;
% F = robin,
% L = williams ;
% F = emilia,
% L = clarke ;
% false.

%------------------------------- Question 3 ----------------------------------

% (3a) 
% find the last element of a list
lastEle(X,[X]).
lastEle(X,[_|L]) :- 
	lastEle(X,L).

% (3b)
% gradeMap(L,R), where L is a list of percentage grade values 
%  (integers from 0 to 100), and R is a list of corresponding grade letters
gradeMap([],[]).
gradeMap([H|T],[X|R]):-
  H >= 80,
  X = a,
  gradeMap(T,R).

gradeMap([H|T],[X|R]):-
  H < 80, H >= 70,
  X = b,
  gradeMap(T,R).

gradeMap([H|T],[X|R]):-
  H < 70, H >= 60,
  X = c,
  gradeMap(T,R).

gradeMap([H|T],[X|R]):-
  H < 60, H >= 50,
  X = d,
  gradeMap(T,R).

gradeMap([H|T],[X|R]):-
  H < 50,
  X = f,
  gradeMap(T,R).

% (3c)
% split(List,Pivot, L1, L2) the lists L1 and L2 are the result of splitting
% the elements List depending on the value of Pivot
split(L,0,[],L).
split([X|Xs],N,[X|Ys],Zs) :- 
	N > 0, N1 is N - 1, 
	split(Xs,N1,Ys,Zs).

% (3d)
% nextto(X, Y, L) succeeds when elements X and Y are immediately consecutive 
%   elements of a list (commented out, replaced in Q4)
% nextto(X,Y,[X,Y|_]).
% nextto(X,Y,[_|Z]) :- 
% 	nextto(X, Y, Z). 

%------------------------------- Question 4 ----------------------------------

% (4a)
% myAppend(L1,L2,L3) to append 2 lists
myAppend([], L, L).
myAppend([X|L1], L2, [X|L3]) :- 
	myAppend(L1, L2, L3).

% (4b)
% myFirst(X,L) that is true if X is the first item in L
myFirst(X,L) :- 
	myAppend([X],_,L).

% (4c) 
% myLast(X,L) from the previous question using append
myLast(X,L) :- 
	myAppend(_,[X],L).

% (4d)
% nextto(X,Y,L) using append
nextto(X,Y,L) :- 
 		myAppend(_,[X,Y|_],L).

% (4e) 
% myReverse(L1,L2) succeeds when the result of
%     reversing the elements of list L1 is the list L2
myReverse([],[]).
myReverse([H|T],R):- 
	myReverse(T,R2), 
	myAppend(R2,[H],R).
	
%------------------------------- Question 5 ----------------------------------	
% (5a)
% list(L) that succeeds if the argument L is a list
list([]).
list([_|T]) :-
    list(T).
	
% (5b)
% treeFlat(T,L) succeeds if the tree T (nested list) has same elements 
%   as the list L
treeFlat([],[]).
treeFlat(X,[X]) :- 
	\+ list(X).   %[^2] this notation from page 88. I like it.
treeFlat([X|Xs],Zs) :- 
	treeFlat(X,Y), 
	treeFlat(Xs,Ys), 
	myAppend(Y,Ys,Zs).

% (5c)
% treeSum(T,S) succeeds if the sum of all elements in the 
%   tree T equals S.
sum([],0).   % this definition for sum is straight from the class notes.
sum([H|T],R):-
    number(H),  %built-in predicate, true if H is bound to a number
    sum(T,S),
    R is S+H.

treeSum(T,S) :-
	treeFlat(T,F),
    sum(F,S).

% (5d)
% this code is taken from the class notes. [^1]
%scaleList(L,C,R) - true if R is the list L scaled by C [^1]

scaleList([],_,[]).
scaleList([H|T],C,[X|R]):-
	X is H*C,
	scaleList(T,C,R).
	
%multList(L1,L2,R) is true if R is the result of multiplying each item in L1 by 
%each item in L2. (Assume len(L1)=len(L2)). [^1]
multList([],[],[]).
multList([H1|T1],[H2|T2],[H|R]):-
	H is H1*H2,
	multList(T1,T2,R).
	
%treeScale(T,R). - true if R is all elements in the tree T multiplied by V  [^1]
treeScale([],_,[]).
treeScale([H|T],V,[X|R]):-
	is_list(H),
	treeScale(H,V,X),
	treeScale(T,V,R).
	
treeScale([H|T],V,[X|R]):- % [^1]
	number(H),
	X is H * V,
	treeScale(T,V,R).

% empty trees are empty, right?
treeMerge([],[],[]).
treeMerge(X,[],X).
treeMerge([],X,X).

%T1 node, T2 tree
treeMerge([H1|T1],[H2|T2],[X|R]):-
  number(H1),
  is_list(H2),
  treeScale(H2,H1,X),
  treeMerge(T1,T2,R).
%T1 tree, T2 node
treeMerge([H1|T1],[H2|T2],[X|R]):-
  is_list(H1),
  number(H2),
  treeScale(H1,H2,X),
  treeMerge(T1,T2,R).
%T1 tree, T2 tree
treeMerge([H1|T1],[H2|T2],[X|R]):-
  is_list(H1),
  is_list(H2),
  treeMerge(H1,H2,X),
  treeMerge(T1,T2,R).
%T1 node, T2 node
treeMerge([H1|T1],[H2|T2],[X|R]):-
  number(H1),
  number(H2),
  X is H1*H2,
  treeMerge(T1,T2,R).
                                                                      
/*
  _            _   _             
 | |_ ___  ___| |_(_)_ __   __ _ 
 | __/ _ \/ __| __| | '_ \ / _` |
 | ||  __/\__ \ |_| | | | | (_| |
  \__\___||___/\__|_|_| |_|\__, |
                           |___/ 
*/
%------------------------------- Question 1 ----------------------------------	
testQ1a:- display("Testing Q1..."),nl,
   display("?-is_mother(diana)."),nl,
   display("Expected: true"),nl,
   display("Actual: "), is_mother(diana).
testQ1b:- display("Testing Q1..."),nl,
   display("?-is_mother(mia)."),nl,
   display("Expected: false"),nl,
   display("Actual: "), is_mother(mia). 
testQ1c:- display("Testing Q1..."),nl,
   display("?-is_father(andrew)."),nl,
   display("Expected: true"),nl,
   display("Actual: "), is_father(andrew).
testQ1d:- display("Testing Q1..."),nl,
   display("?-is_father(meghan)."),nl,
   display("Expected: false"),nl,
   display("Actual: "), is_father(meghan).
testQ1e:- display("Testing Q1..."),nl,
   display("?- parent(anne,peter)."),nl,
   display("Expected: true"),nl,
   display("Actual: "), parent(anne,peter).
testQ1f:- display("Testing Q1..."),nl,
   display("?- parent(charles,roger)."),nl,
   display("Expected: false"),nl,
   display("Actual: "), parent(charles,roger).
testQ1g:- display("Testing Q1..."),nl,
   display("?- different(mia,roger)."),nl,
   display("Expected: true"),nl,
   display("Actual: "), different(mia,roger).
testQ1h:- display("Testing Q1..."),nl,
   display("?- different(roger,roger)."),nl,
   display("Expected: false"),nl,
   display("Actual: "), different(roger,roger).
testQ1i:- display("Testing Q1..."),nl,
   display("sister(eugenie,beatrice).."),nl,
   display("Expected: true"),nl,
   display("Actual: "), sister(eugenie,beatrice).
testQ1j:- display("Testing Q1..."),nl,
   display("sister(henry,william)."),nl,
   display("Expected: false"),nl,
   display("Actual: "), sister(henry,william).
testQ1k:- display("Testing Q1..."),nl,
   display("brother(henry,william)."),nl,
   display("Expected: true"),nl,
   display("Actual: "), brother(henry,william).
testQ1l:- display("Testing Q1..."),nl,
   display("?- brother(eugenie,beatrice)."),nl,
   display("Expected: false"),nl,
   display("Actual: "), brother(eugenie,beatrice).

/*
%------------------------------- Question 3 ----------------------------------	
% 3a 
% ?- lastEle(X,[how,are,you,today]).
% X=today.
% ?-gradeMap([0, 16, 49, 55, 63, 78, 92], R).
% R=[f,f,f,d,c,b,a]
%3c
% ?-split([4,7,1,8,2,9,3],5, L1, L2).
% L1 = [4,1,2,3]
% L2 = [7, 8, 9].
?-split([4,7,1,8,2,9,3],5, [4,1,2,3], [7, 8, 9]).
False.
?- split([4,7,1,8,2,9,3],10, L1, L2).
false.
?- split([[4,7],1,8,2,9,3],5, L1, L2).
L1 = [[4, 7], 1, 8, 2, 9],
L2 = [3] .
?- split([[4,7],1,8,2,9,3],2, L1, L2).
L1 = [[4, 7], 1],
L2 = [8, 2, 9, 3] .
?- split([[4,7],1,8,2,9,3],1, L1, L2).
L1 = [[4, 7]],
L2 = [1, 8, 2, 9, 3] .
3d										   
[4 marks] Write a predicate nextto(X, Y, L), that succeeds when elements X and Y
 are immediately consecutive elements of a list L. E.g., 
?- nextto(a,b, [c,a,b,d]).
True.
?- nextto(a,b, [c,a,d,b]).
False
?- nextto([a,b],[c,d], [c,[a,b],[c,d],b]).
true ;
false.
?- nextto([a,b],[c,d], [c,[a,b],e,[c,d],b]).
false.
?- nextto(c,d,[a,b,[c,d],e]).
false. (this is expected)
4b
?- myFirst(a,[a,b,c,d,e]).
true.
?- myFirst(d,[a,b,c,d,e]).
false.
?- myFirst(a,[[a],b,c,d,e]).
false.
?- myFirst([a],[[a],b,c,d,e]).
true.
?- myFirst([],[]).
false.
?- myFirst([],[a,b]).
false.
4c.
?- myLast(a,[a,b,c,d,e,a]).
true ;
false.
?- myLast(d,[a,b,c,d,e]).
false.
?- myLast([e],[a,b,c,d,[e]]).
true ;
false.
4d
?- nextto(a,b, [c,a,b,d]).
True.
?- nextto(a,b, [c,a,d,b]).
False
?- nextto([a,b],[c,d], [c,[a,b],[c,d],b]).
true ;
false.
?- nextto([a,b],[c,d], [c,[a,b],e,[c,d],b]).
false.
?- nextto(c,d,[a,b,[c,d],e]).
false. (this is expected)
?- nextto([],1,[[],1]).
true . (this is expected)
4e.
?- myReverse([a,b,c],[c,b,a]).
true.
?- myReverse([a,b,c],L).
L = [c, b, a].
?- myReverse([a,[a,b],c],L).
L = [c, [a, b], a].
5a
?- list([a]).
true.
?- list([[a],b]).
true.
?- list([a,b]).
true.
?- list(a).
false.

*/
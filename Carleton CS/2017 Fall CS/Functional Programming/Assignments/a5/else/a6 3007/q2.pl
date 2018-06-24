% 1
/** Facts*/
male(sammy).
male(jonny).
male(bob).
male(jean).
male(ben).
female(pepi).
female(esther).
female(eliana).
female(rebecca).
father(bob, eliana).
father(bob, sammy).
father(bob, jonny).
father(jean, rebecca).
father(jean, esther).
father(jean, ben).
mother(rebecca, eliana).
mother(rebecca, sammy).
mother(rebecca, jonny).
mother(pepi,rebecca).
mother(pepi,esther).
mother(pepi,ben).
married(rebecca,bob).
married(jean,pepi).


is_mother(X) :- parent(X,_), female(X).
is_father(X) :- parent(X,_), male(X).

different(X,Y) :- \+ (X == Y).

parent(X, Y) :- father(X, Y).
parent(X, Y) :- mother(X, Y).

grandfather(X, Y) :- father(X, Z), parent(Z, Y) , male(X). /* Rule  3 */
grandmother(X, Y) :- female(X), mother(X, Z), parent(Z, Y). /* Rule  4 */

brother(X,Y) :- parent(Z,X), parent(Z,Y), male(X).
sister(X,Y) :- parent(Z,X), parent(Z,Y), female(X).

ancestor(X,Y) :- parent(X, Y) ; grandfather(X, Y) ; grandmother(X, Y).

aunt(X,Y) :- female(X),sister(X,Mom),parent(Mom,Y).
aunt(X,Y) :- female(X),sister(X,Dad),parent(Dad,Y).
uncle(X,Y) :- brother(X,Par),parent(Par,Y).




% 2
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

movie(year(2003), title([pirates,of,the,carribean]), cast([actor(jonny, depp), actor(keira, knightley), actor(orlando, bloom)])).
movie(year(2014), title([guardians, of, the, galaxy]), cast([actor(chris, pratt), actor(karen,gillan) ])).
movie(year(1988), title([die,hard]), cast([actor(bruce, willis)])).
movie(year(2001), title([lord,of,the,rings]), cast([actor(orlando, bloom), actor(sean, bean)])).
movie(year(2016), title([xmen, apocalypse]), cast([actor(jennifer,lawrence), actor(james, mcavoy)])).
movie(year(2014), title([the,imitation,game]), cast([actor(benedict, cumberbatch), actor(keira, knightley)])).
movie(year(2012), title([the,hunger,games]), cast([actor(jennifer,lawrence)])).
movie(year(2016), title([deadpool]), cast([actor(ryan, reynolds)])).

% a: movie(year(Y),Title,_), Y=<2010.
/* RESULTS
Title = title([pirates, of, the, carribean])
Title = title([die, hard])
Title = title([lord, of, the, rings])
*/

% b: movie(_,title(Title),_) , member(of, Title), member(the, Title).
 /* RESULTS
Title = [pirates, of, the, carribean] .
Title = [guardians, of, the, galaxy]
Title = [lord, of, the, rings]
*/

% c:  movie(_,title(Title1),cast(Cast1)) , member(X, Cast1),movie(_,title(Title2),cast(Cast2)),  member(Y, Cast2), Title1 \= Title2.
/* RESULTS
Title1 = [pirates, of, the, carribean],
Cast1 = [actor(jonny, depp), actor(keira, knightley), actor(orlando, bloom)],
X = actor(jonny, depp),
Title2 = [guardians, of, the, galaxy],
Cast2 = [actor(chris, pratt), actor(karen, gillan)],
Y = actor(chris, pratt) .
*/


% d: movie(_,T,cast(C)),member(actor(chris,_),C).
/* RESULTS
T = title([guardians, of, the, galaxy]),
C = [actor(chris, pratt), actor(karen, gillan)] .
*/

% e: actor(X,Y,gender(Z)),Z=female.
 /*
 X = glenn,
 Y = close,
 Z = female .
 */

% f: movie(_,T,cast(C)),member(actor(sean,bean),C).
 /*
 T = title([lord, of, the, rings]),
C = [actor(orlando, bloom), actor(sean, bean)] .
 */

% g: movie(_,title(Title1),cast(Cast1)) , member(X, Cast1),movie(_,title(Title2),cast(Cast2)),  member(Y, Cast2), Title1 \= Title2.
/*
Title1 = [pirates, of, the, carribean],
Cast1 = [actor(jonny, depp), actor(keira, knightley), actor(orlando, bloom)],
X = actor(jonny, depp),
Title2 = [guardians, of, the, galaxy],
Cast2 = [actor(chris, pratt), actor(karen, gillan)],
Y = actor(chris, pratt) .
*/

% h: movie(year(Y), T,_), \+ ( movie(year(X),_,_), X<Y).
/*
Y = 1988,
T = title([die, hard]) .
*/

% i: actor(F,L,_), not((movie(_,_,cast(C)), member(actor(F,L),C))).
 /*
 F = glenn,
 L = close .
*/


% 3a
lastEle(X,[X|[]]).
lastEle(X,[_|T]) :- lastEle(X,T).


% 3b
gradeMap([],[]).
gradeMap([H|T],[a|R]):-
  H>=81,H=<100,
  gradeMap(T,R).
gradeMap([H|T],[b|R]):-
  H>=71,
  H=<80,
  gradeMap(T,R).
gradeMap([H|T],[c|R]):-
  H>=61,
  H=<70,
  gradeMap(T,R).
gradeMap([H|T],[d|R]):-
  H>=51,
  H=<60,
  gradeMap(T,R).
gradeMap([H|T],[f|R]):-
  H>=0,
  H=<50,
  gradeMap(T,R).


% 3c
split([],Pivot,[],[]).

split([H|T],Pivot,[H|L1],L2):-
  H=<Pivot, split(T,Pivot,L1,L2).

split([H|T],Pivot,L1,[H|L2]):-
  H>Pivot, split(T,Pivot,L1,L2).



% 3d

  nextto(X, Y, [X,Y|_]).
nextto(X, Y, [_|Tail]) :-
    nextto(X, Y, Tail).



% 4a
    myAppend([],[],[]).

    myAppend([H|T],Y,[H|L]) :-
      myAppend(T,Y,L).

    myAppend(X,[H|T],[H|L]) :-
      myAppend(X,T,L).

% 4b

      myFirst(X,L):-
        myAppend([X],_,L).

% 4c
      myLast(X,L):-
        myAppend(_,[X],L).

% 4d
        nexttto(X,Y,L) :-
         		myAppend(_,[X,Y|_],L).

% 4e
        myReverse([],[]).
        myReverse([H|T],R):-
        	myReverse(T,R2),
        	myAppend(R2,[H],R).


% 5a
          list(X) :-
                  var(X), !,
                  fail.
          list([]).
          list([_|T]) :-
                  list(T).

% 5b
    treeFlat([], []) :- !.
    treeFlat([L|Ls], FlatL) :-
        !,
        treeFlat(L, NewL),
        treeFlat(Ls, NewLs),
        append(NewL, NewLs, FlatL).
    treeFlat(L, [L]).

% coronavirus/4 country  # of cases  # of deaths # of recoveries
coronavirus(unitedstates,586057,23604,43637).
coronavirus(spain,170099,17756,64727).
coronavirus(italy,159516,20465,35435).
coronavirus(germany,130072,3194,57259).
coronavirus(france,98076,14967,27718).

%population/2
population(unitedstates,331002651).
population(spain,46754778).
population(italy,60451826).
population(germany,83783942).
population(france,65273511).

% Rules
recovery_rate(Country, Rate) :- coronavirus(Country, Cases, _, Recoveries),
                                Rate is Recoveries / Cases * 100.
mortality_rate(Country, Rate) :- coronavirus(Country, Cases, Deaths, _),
                                Rate is Deaths / Cases * 100.

is_integer(X) :- member(X, [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]).

% equation A + B = C
equation(A, B, C) :-
                     is_integer(A),
                     is_integer(B),
		     C is A + B.

% same_num/2
same_num(A, A).

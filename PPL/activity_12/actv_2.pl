student(grace).
student(omar).
student(pablo).
student(molly).
student(anthony).

faculty(david).

csMajor(grace).
csMajor(omar).
chemMajor(pablo).
hisMajor(molly).
bioMajor(anthony).

cs3210(grace).
cs3600(grace).
cs3600(omar).
che3190(david).
che3190(pablo).
che3200(pablo).
bio1080(molly).
bio1080(anthony).

hire(X) :- csMajor(X), cs3210(X).
hire(X) :- student(X), che3190(X).
hire(X) :- bioMajor(X).


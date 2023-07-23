program this_confuses;
uses crt;
var
        x, y : integer;
begin
        clrscr;
        x:=10;
        y:=10 ;

        x:=x*x;
        y:=x;

        if (x<y) then x:=y-1
        else if (x>y) then x:=y+1;
        x:=x div x;
        writeln(x ,' ', y)
end.
program Waduh_gaawat;
uses crt;
var
        a,b,c,d : integer;
begin
        clrscr;
        a:=64;
        b:=8;
        c:=0;
        d:=0;

        while (a>b) do
        begin
                a:=a-b;
                c:=c+1;
                d:=d+b;
        end;
writeln(c ,' ', d);
end.
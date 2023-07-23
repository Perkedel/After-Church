program swag_swagger;
uses crt;

function swag(x:integer):integer;
begin
        if (x<7) then swag:=x
        else swag:=swag(x mod 7)*swag(x div 7)*7;
end;

begin
        clrscr;
        writeln(swag(22));
end.
{
En una empresa de taxis, se registran datos de los N autos que la misma posee. Para cada auto, se tiene: Patente (cadena de 7), viajes realizados en agosto (>0), valor facturado en agosto.
Se pide: ingresar los datos mencionados desde teclado, hallar e informar:
   -   el porcentaje de autos que han facturado más de X (siendo X un dato ingresado previamente)
   -  patente del auto que realizó la menor cantidad de viajes (suponerlo único).
}
program DiagnosticoTaxis;

const
  MAX_AUTOS = 100;

type
  PatenteStr = string[7];
  AutoRegistro = record
    patente: PatenteStr;
    viajesEnAgosto: word;
    valorFacturado: word;
  end;
  AutosArray = array [1..MAX_AUTOS] of AutoRegistro;

procedure LeerDatosAutos(var autos: AutosArray; var cantidad: byte);
var
  i: byte;
begin
  Write('Ingrese la cantidad de autos: ');
  ReadLn(cantidad);
  for i := 1 to cantidad do
  begin
    WriteLn('Ingrese los datos del auto ', i, ':');
    Write('Patente: ');
    ReadLn(autos[i].patente);
    Write('Viajes realizados en agosto: ');
    ReadLn(autos[i].viajesEnAgosto);
    Write('Valor facturado en agosto: ');
    ReadLn(autos[i].valorFacturado);
  end;
end;

function CalcularPorcentajeFacturacionSuperiorA(valorLimite: word; autos: AutosArray; cantidad: byte): real;
var
  i, conteo: byte;
begin
  conteo := 0;
  for i := 1 to cantidad do
  begin
    if autos[i].valorFacturado > valorLimite then
      conteo := conteo + 1;
  end;
  if cantidad > 0 then
    CalcularPorcentajeFacturacionSuperiorA := (conteo / cantidad) * 100
  else
    CalcularPorcentajeFacturacionSuperiorA := 0;
end;

procedure EncontrarAutoConMenosViajes(autos: AutosArray; cantidad: byte);
var
  i: byte;
  patenteMenorViajes: PatenteStr;
  viajesMenores: word;
begin
  if cantidad > 0 then
  begin
    patenteMenorViajes := autos[1].patente;
    viajesMenores := autos[1].viajesEnAgosto;
    for i := 2 to cantidad do
    begin
      if autos[i].viajesEnAgosto < viajesMenores then
      begin
        viajesMenores := autos[i].viajesEnAgosto;
        patenteMenorViajes := autos[i].patente;
      end;
    end;
    WriteLn('Patente del auto con la menor cantidad de viajes: ', patenteMenorViajes);
  end
  else
    WriteLn('No hay autos registrados.');
end;

var
  autos: AutosArray;
  cantidad: byte;
  valorComparacion: word;
  
begin
  LeerDatosAutos(autos, cantidad);
  
  Write('Ingrese un valor de facturación para comparar: ');
  ReadLn(valorComparacion);
  
  WriteLn('Porcentaje de autos que han facturado más de ', valorComparacion, ': ', CalcularPorcentajeFacturacionSuperiorA(valorComparacion, autos, cantidad):0:2, '%');
  
  EncontrarAutoConMenosViajes(autos, cantidad);
  
  ReadLn;
end.
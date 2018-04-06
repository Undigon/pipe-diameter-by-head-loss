<html lang="es">
<meta charset="utf-8" />
<script>
document.write("<h1>Creado por Rodrigo Iván Avila Demitroff. 2018.</h1>");
document.write("<div>Este documento contiene un pequeño programa en JavaScript.</div>");
document.write("<div>Acepta notación científica. Ejemplo 2.3e-2 = 0.023</div>");
document.write("<div>Cancelar cuando pide el nuevo coeficiente de fricción cierra la caja de diálogo.<div/>");
document.write("<div></div>");

var caudal = prompt("Caudal [m³/s]");
var longitud = prompt("Longitud de la conducción [m]");
var headLoss = prompt("Pérdida máxima de cabeza [m]");
var viscosidad = prompt("Viscosidad dinámica [kg/m·s]");
var densidad = prompt("Densidad [kg/m³]");
var rugosidad = prompt("Rugosidad absoluta [m]");
var a = 0.0;
var reConst = 0.0;
var f_i = 0.04;
var g = 9.81;
var ith = 1;
var seguir = true;

a = 8 * caudal**2 * longitud / (headLoss * g * Math.pow(Math.PI, 2));
reConst = 4 * caudal / (Math.PI * (viscosidad/densidad));
while (seguir){
	document.write("<p><div>Diámetro"+ith+": "+Math.pow((a*f_i),(1/5))+" m</div>");
	document.write("<div>Rugosidad relativa"+ith+": "+rugosidad/((a*f_i)**(1/5))+"</div>");
	document.write("<div>Reynolds"+ith+": "+reConst/Math.pow(a*f_i,1/5)+"</div></p>");
	f_i = prompt("¿Nuevo coeficiente de fricción?");
	if (f_i == null || f_i == "") {seguir = false;}
	ith++;
}
</script>

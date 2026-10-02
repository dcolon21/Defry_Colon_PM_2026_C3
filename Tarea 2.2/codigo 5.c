/* El conjunto de instrucciones muestra la sintaxis de la estructura switch
➥en C. */
. . .
switch(<selector>)
{
case <valor1> : <acción1>;
break; /* Para salir del switch */
case <valor2> :
case <valor3> :
case <valor4> : <acción2>;
break;
case <valor5> :
case <valor6> : <acción3>;
break;
default: : <acciónx>;
break;
}
acciónY;

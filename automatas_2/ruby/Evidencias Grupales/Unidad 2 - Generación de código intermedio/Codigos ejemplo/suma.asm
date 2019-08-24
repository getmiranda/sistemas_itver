	DOSSEG
	.MODEL small
	.8086
	
	.DATA 
msj	db	"Introduce un numero: ", "$"
msj2	db	"El resultado de la suma es: ", "$"
n1	db	0h
n2	db	0h

	.CODE
main	PROC FAR
	
	;Inicio del segmento de dato optimo
	mov ax.DGROUP
	mov	ds,ax
	
	;Limpia pantalla
	mov	ah,00h
	mov al,03h
	int 10h

	;Imprime en pantalla el primer mensaje
	mov dx,OFFSET msj
	mov ah, 9
	int 21h

	;lee el primer digito
	mov ah,01h
	int 21h

	;Realiza conversion de decimal a hexadecimal
	sub al,30h
	mov n1,al

	;lee el segundo digito
	mov ah,01h
	int 21h

	;Realiza conversion de decimal a hexadecimal
	sub al,30h
	mov n2,al

	;Realiza suma aritmetica n1 + n2
	mov bl,n2
	add bl,n1

	;Imprime el segundo mensaje de resultado
	mov dx,OFFSET msj2
	mov ah, 9
	int 21h

	;Realiza conversion para imprimir
	mov dl,bl
	add dl,30h

	;Imprimir el numero
	mov ah,02h
	int 21h

	;Devuelve el control al DOS
	mov ah,4Ch
	int 21h
	
main	ENDP
		END
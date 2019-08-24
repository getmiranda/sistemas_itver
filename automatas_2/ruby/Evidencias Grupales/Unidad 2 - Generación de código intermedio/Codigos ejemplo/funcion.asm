		DOSSEG
		.MODEL small
		.8086
	
		.DATA 
msj		db	"Introduce la base: ", "$"
msj2	db	"Introduce el exponente: ", "$"
msj3	db	"El resultado de la potencia es: ", "$"
n1	db	0h
n2	db	0h
resp	db 0h

		.CODE
main	PROC	FAR
	
		;Inicio del segmento de dato optimo
		mov	ax,DGROUP
		mov	ds,ax
		
		;Limpia pantalla
		mov	ah,00h
		mov	al,03h
		int 10h

		;Imprime en pantalla el primer mensaje
		mov	dx,OFFSET msj
		mov	ah, 9
		int 21h

		;lee la base
		mov	ah,01h
		int 21h

		;Realiza conversion de decimal a hexadecimal
		sub	al,30h
		mov	n1,al

		;Imprime en pantalla el segundo mensaje
		mov	dx,OFFSET msj2
		mov	ah, 9
		int 21h

		;lee el exponente
		mov ah,01h
		int 21h

		;Realiza conversion de decimal a hexadecimal
		sub al,30h
		mov n2,al

		;Realiza operacion potencia
		mov ax,n1
		mov cx,n2
		dec cx
mas:	mul n1
		loop mas
		mov res,ax

		;Imprime el tercer mensaje de resultado
		mov dx,OFFSET msj3
		mov ah, 9
		int 21h

		;Realiza conversion para imprimir
		mov dx,res
		add dx,30h

		;Imprimir el numero
		mov ah,02h
		int 21h

		;Devuelve el control al DOS
		mov ah,4Ch
		int 21h
	
main	ENDP
		END
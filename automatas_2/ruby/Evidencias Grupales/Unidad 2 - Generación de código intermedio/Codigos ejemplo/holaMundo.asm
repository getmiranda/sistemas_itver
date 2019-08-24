	DOSSEG
	.MODEL small
	.8086

	.STACK 300h

	.DATA 
msj	db	"Hola Mundo!", "$"

	.CODE
main	PROC FAR
	
	;Inicio del segmento de dato optimo
	mov ax.DGROUP
	mov	ds,ax

	;Programa que imprime en pantalla el mansaje "Hola Mundo!"
	
	;Limpia pantalla
	mov	ah,00h
	mov al,03h
	int 10h

	;Imprime en pantalla
	mov dx,OFFSET msj
	mov ah, 9
	int 21h

	;Devuelve el control al DOS (Sistema operativo)
	mov ah,4Ch
	int 21h
	
main	ENDP
		END
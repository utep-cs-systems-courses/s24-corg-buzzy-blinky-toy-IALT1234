	.arch msp430g2553
	.p2align 1,0
	.text

	.global greenControl
	
	.extern P1OUT


greenControl:

	cmp #0, r12
	jz off
	bis #BIT6, &P1OUT	; turn on green led with P1.3
	pop r0
off:
	bic #BIT6, &P1OUT	;turn off
	pop r0

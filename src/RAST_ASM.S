				xdef		_clear_screen
				xdef		_fill_screen

; ------------------ {SUBROUTINE: _clear_screen } ------------------
; quick clear that uses movem to reduce fetch-execute cycle overhead
; 
; takes about half the number of clock cycles as the code in clear.s, 
; and so runs in about 1/100th of a second (at 8MHz) instead of 1/50th
;

base			equ			64					; offset from SP (not a6)

_clear_screen:	movem.l		d0-7/a0-6,-(sp)
				lea			zeroes,a0	
				movem.l		(a0)+,d1-7/a1-6
				movea.l		base(sp),a0
				adda.l 		#32000,a0
				move.w		#614,d0

fill_loop:		movem.l		d1-7/a1-6,-(a0)
				dbra		d0,fill_loop
				movem.l 	d1-5,-(a0)
				movem.l		(sp)+,d0-7/a0-6
				rts

; ------------------ {SUBROUTINE: _fill_screen } ------------------
; using the same method as _clear_screen, entirely fills the screen with pixels
;
; uses same base offset as _clear_screen
;

_fill_screen:	movem.l		d0-7/a0-6,-(sp)
				lea			ones,a0	
				movem.l		(a0)+,d1-7/a1-6
				movea.l		base(sp),a0
				adda.l 		#32000,a0
				move.w		#614,d0

fill_loop_b:	movem.l		d1-7/a1-6,-(a0)
				dbra		d0,fill_loop_b
				movem.l 	d1-5,-(a0)
				movem.l		(sp)+,d0-7/a0-6
				rts

zeroes:			ds.l		13
ones:			dcb.l		13,$FFFFFFFF



				AREA ASM_func, CODE, READONLY				


nome_fne			PROC
					EXPORT 	nome_fne

					PUSH	{R4-R8,R10-R11,LR}

					POP		{R4-R8,R10-R11,PC}
					ENDP
					
					
					END

default:				organizer

organizer:				main.o managefiles.o split_file_name.o copy_file.o
						gcc main.o managefiles.o split_file_name.o copy_file.o -o organizer

main.o:					main.c 
						gcc -c main.c	

managefiles.o: 			managefiles.c
						gcc -c managefiles.c

split_file_name.o: 		split_file_name.c
						gcc -c split_file_name.c

copy_file.o:  			copy_file.c
			  			gcc -c copy_file.c

clean:
						$(RM) organizer main.o managefiles.o split_file_name.o copy_file.o
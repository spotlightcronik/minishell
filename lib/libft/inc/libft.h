/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:14:25 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/25 14:43:38 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

//= STRUCTS =//

/*
 * Estructure to keep data in a linked list.
 * @param content Pointer to the content stored in the node.
 * @param next Pointer to the next node in the list,
		or NULL if it's the last node.
 * @param prev Pointer to the previous node in the list,
		or NULL if it's the first node.
 */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef enum e_bool
{
	false,
	true,
}					t_bool;

//= Character Functions =//

/*
 * Checks for an alphabetic character; in the standard "C" locale,
 * it is equivalent to (isupper(c) || islower(c)).
 * @param[in] c Character to be checked.
 */
int					ft_isalpha(int c);

/*
 * Checks for an numeric character; from '0' to '9'.
 */
int					ft_isdigit(int c);

/*
 * Checks for an alphanumeric character; it is equivalent to
 * (isalpha(c) || isdigit(c)).
 */
int					ft_isalnum(int c);

/*
 * Checks whether c is a 7-bit unsigned char value that fits into
 * the ASCII character set
 */
int					ft_isascii(int c);

/*
 * Checks for any printable character including space.
 */
int					ft_isprint(int c);

/*
 * checks for white-space characters. In the "C" and "POSIX" locales,
 *   these are: space, form-feed ('\f'), newline ('\n'), carriage
 *   return ('\r'), horizontal tab ('\t'), and vertical tab ('\v').
 */
int					ft_isspace(int c);

//= Integer Functions =//

/* Returns the highest of two numbers.
 * @param[in] a First integer.
 * @param[in] b Second integer.
 * @returns the highest of the two integers.
 */
int					ft_highest(int a, int b);

/* Returns the lowest of two numbers.
 * @param[in] a First integer.
 * @param[in] b Second integer.
 * @returns the lowest of the two integers.
 */
int					ft_lowest(int a, int b);

/* Gets the power of a given base to a power exponent.
   Accepts negative base and power, result must be within an integer size;
 * @param[in] base of the exponent, number to multiply.
 * @param[in] power of the exponent, times to multiply.
 * @returns Base raised to the power of power.
 */
int					ft_pwr(int base, int power);

//= Basic String Functions =//

/*
 * Gets the length (not including the NULL char) of a string.
 * @param[in] c String to get the length of.
 * @returns The length of the string.
 */
size_t				ft_strlen(const char *c);

/*
 * Copies a string into another null terminating the result.
 * @param[in] dst Pointer to the string to copy to.
 * @param[in] src Pointer to the string to copy from.
 * @param[in] size number of bytes to copy, it includes the NULL character.
 * @returns Number of bytes of the resulting string,
 *   useful for calculating truncation
 */
size_t				ft_strlcpy(char *dst, const char *src, size_t size);

/*
 * Concatenates a string with another null terminating the result.
 * @param[in] dst Pointer to the string to concatenate to.
 * @param[in] src Pointer to the string to concatenate.
 * @param[in] size number of bytes to of the end result,
 *   it includes the NULL character.
 * @returns Number of bytes of the resulting string, if it traversed size bytes
 *   without finding a NULL character it will return size instead
 */
size_t				ft_strlcat(char *dst, const char *src, size_t size);

/*
 * Turns a character into uppercase if it is possible.
 * @param[in] c Character to turn uppercase.
 * @returns int of the character recieved or the uppercase if it's alphabetic.
 */
int					ft_toupper(int c);

/*
 * Turns a character into lowercase if it is possible.
 * @param[in] c Character to turn lowercase.
 * @returns int of the character recieved or the lowercase if it's alphabetic.
 */
int					ft_tolower(int c);

/*
 * Search a character inside a string from start to finish.
 * @param[in] s String where to search the character.
 * @param[in] c Character to be searched.
 * @returns Pointer to the first occurrence of that character.
 */
char				*ft_strchr(const char *s, int c);

/*
 * Search a character inside a string from end to start.
 * @param[in] s String where to search the character.
 * @param[in] c Character to be searched.
 * @returns Pointer to the last occurrence of that character.
 */
char				*ft_strrchr(const char *s, int c);

/*
 * Compares two strings.
 * @param[in] s1 First string for the comparison.
 * @param[in] s2 Second string for the comparison.
 * @returns Difference in the ascii code of the first different character,
 *   or 0 if both strings are equal.
 */
int					ft_strcmp(char *s1, char *s2);

/*
 * Compares two strings up to a set length.
 * @param[in] s1 First string for the comparison.
 * @param[in] s2 Second string for the comparison.
 * @param[in] n Number of bytes to compare.
 * @returns Difference in the ascii code of the first different character,
 *   or 0 if both strings are equal up to n bytes.
 */
int					ft_strncmp(const char *s1, const char *s2, size_t n);

/*
 * Searches a string inside another string up to a set length.
 * @param[in] big String to be search in.
 * @param[in] little String to search.
 * @param[in] n Number of bytes inside the big string to search for.
 * @returns Pointer to the start of the little string in the big string,
 *   or NULL if it is not found.
 */
char				*ft_strnstr(const char *big, const char *little,
						size_t len);

/*
 * Counts the number of occurrences of a character inside a string.
 * @param[in] str String to count the characters in.
 * @param[in] c Character to count.
 * @returns Count of that character inside the string.
 */
int					ft_charcount(const char *str, char c);

/*
 * Applies a function to each character in the string.
 * @param[in] s String to apply the function to.
 * @param[in] f Function to apply to each character.
 */
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

//= ALLOCATING STRING FUNCTIONS =//

/*
 * Creates a duplicate of a string
 * @param[in] s String to be duplicated
 * @returns Pointer to the string duplicated,
 *   or NULL if malloc had an error.
 */
char				*ft_strdup(const char *s);

/*
 * Creates a new string from a part of another string.
 * @param[in] s String to source the new string.
 * @param[in] start Index of the sourcce string to start to create the string.
 * @param[in] len Length of the new string to create not including NULL char.
 * @returns Pointer to the new string or NULL if malloc errored
 */
char				*ft_substr(char const *s, unsigned int start, size_t len);

/*
 * Creates a new string joining both of the strings provided.
 * @param[in] s1 Left string of the join.
 * @param[in] s2 Right string of the join.
 * @returns pointer to the new string or NULL if malloc errored.
 */
char				*ft_strjoin(char const *s1, char const *s2);

/*
 * Realized a join and frees the left sided string,
 * @param[in] s1 Left string of the join.
 * @param[in] s2 Right string of the join.
 * @returns pointer to the new string or NULL if malloc errored.
 */
char				*ft_freejoin(char *s1, char *s2);

/*
 * Creates a new string removing a set of characters from the end/start
 *   of a string.
 * @param[in] s1 String to source the new string.
 * @param[in] set Set of characters to remove from the source string.
 * @returns pointer to the new string or NULL if malloc errored.
 */
char				*ft_strtrim(char const *s1, char const *set);

/*

* Creates an array of string from a source string splitting it by the delimiter.
 * @param[in] s Source string.
 * @param[in] c Delimiter to split the string by.
 * @returns Double pointer to the new set of string
 *   terminated with a pointer to NULL, or NULL if malloc errored.
 */
char				**ft_split(char const *s, char c);

/*
 * Applies a function to each character in the string.
 * @param[in] s String to apply the function to.
 * @param[in] f Function to apply to each character.
 * @returns Pointer to the new string or NULL if malloc errored.
 */
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

//= Memory functions =//

/*
 * Set a range of memory to a set value.
 * @param[in] s Pointer to the start of the memory range to be changed.
 * @param[in] c Value to change the memory to.
 * @param[in] n Number of bytes to be change.
 * @returns Pointer to the start of the memory range changed.
 */
void				*ft_memset(void *s, int c, size_t n);

/*
 * Sets a range of memory to 0.
 * @param[in] s Pointer to the start of the memory range.
 * @param[in] n Number of bytes to set.
 */
void				ft_bzero(void *s, size_t n);

/*
 * Copies a range of memory to another.
 * @param[in] dest Target pointer for the memory range to copy to.
 * @param[in] src Source pointer for the memory range to be copied from.
 * @param[in] n Size of the memory range.
 * @returns Pointer to the start of target memory range.
 */
void				*ft_memcpy(void *dest, const void *src, size_t n);

/*
 * Copies a range of memory to another checking for overlaps.
 * @param[in] dest Target pointer for the memory range to copy to.
 * @param[in] src Source pointer for the memory range to be copied from.
 * @param[in] n Size of the memory range.
 * @returns Pointer to the start of target memory range.
 */
void				*ft_memmove(void *dest, const void *src, size_t n);

/*
 * Search for a value inside a range of memory.
 * @param[in] *s Pointer to the sstart of the memory range.
 * @param[in] c Value to search for.
 * @param[in] n Size of the memory range.
 * @returns Pointer to the first occurrence of the target value.
 */
void				*ft_memchr(const void *s, int c, size_t n);

/*
 * Compares two ranges of memory and returns the first difference it finds.
 * @param[in] s1 First range of memory to compare.
 * @param[in] s2 Second range of memory to compare.
 * @param[im] n Number of bytes to compare.
 * @returns Difference of the first different values it finds.
 */
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/*
 * Allocates memory for a set of members controlling overflow
 *   and sets it's contents to 0.
 * @param[in] nmemb Number of members to allocate for.
 * @param[in] size Size each memeber.
 * @returns Pointer to the alloced memory.
 */
void				*ft_calloc(size_t nmemb, size_t size);

//= PRINTING FUNCTIONS =//

/*
 * Write formatted text into stdout.
 */
ssize_t				ft_printf(char const *str, ...);

/*
 * Write formatted text into stdout.
 */
ssize_t				ft_fprintf(int fd, char const *str, ...);

/*
 * Write a char to a file descriptor.
 * @param[in] c Character to write.
 * @param[in] fd File descriptor to write to.
 */
ssize_t				ft_putchar_fd(char c, int fd);

/*
 * Write a string to a file descriptor.
 * @param[in] s String to write.
 * @param[in] fd File descriptor to write to.
 */
ssize_t				ft_putstr_fd(char *s, int fd);

/*
 * Write a string terminating it in a new line to a file descriptor.
 * @param[in] s String to write.
 * @param[in] fd File descriptor to write to.
 */
ssize_t				ft_putendl_fd(char *s, int fd);

/*
 * Write a number to a file descriptor.
 * @param[in] n Number to write.
 * @param[in] fd File descriptor to write to.
 */
ssize_t				ft_putnbr_fd(int n, int fd);

//= CONVERSION FUNCTIONS =//

/*
 * Converts a number inside a string into an integer.
 * @param[in] nptr Pointer to the string containing the number.
 * @returns Integer equal to the provided number and 0 if wrong formatted.
 */
int					ft_atoi(const char *nptr);

/*
 * Converts a integer into a string.
 * @param[in] n Number to convert.
 * @returns String picturing the provided number.
 */
char				*ft_itoa(int n);

/*
 * Converts a linked list into an array.
 * @param[in] lst Pointer to the node from which to start.
 * @returns Array of pointers to the contents of the list.
 */
void				**ft_lsttoarr(t_list *lst);

//= LINKED LISTS =//

/*
 * Creates a new list node.
 * @param[in] content Pointer to set inside the node.
 * @returns Pointer to the created node list having both directions
 *   pointers set as NULL if it could not be allocated returns NULL
 */
t_list				*ft_lstnew(void *content);

/*
 * Add a new new node to the front of the list.
 * @param[in] lst Memory address of the first node of the list.
 * @param[in] new Pointer to the node to add to the list.
 */
void				ft_lstadd_front(t_list **lst, t_list *new);

/*
 * Add a new new node to the back of the list.
 * @param[in] lst Memory address of the first node of the list.
 * @param[in] new Pointer to the node to add to the list.
 */
void				ft_lstadd_back(t_list **lst, t_list *new);

/*
 * Insert a new node inside the list after a given node.
 * @param[in] node Node after which to insert the new node.
 * @param[in] insert Node to insert after the given node.
 * @returns node inserted, in case of wanting to work with it after insertion.
 */
t_list				*ft_lstinsert(t_list *node, t_list *insert);

/*
 * Gets the full size of the list from the node given.
 * @param[in] lst Node of the list.
 * @returns number of nodes in the list.
 */
int					ft_lstsize(t_list *lst);

/*
 * Gets the next side size of the list from the node given.
 * @param[in] lst Node of the list.
 * @returns number of nodes in the list.
 */
int					ft_lstnextsize(t_list *lst);

/*
 * Gets the prev side size of the list from the node given.
 * @param[in] lst Node of the list.
 * @returns number of nodes in the list.
 */
int					ft_lstprevsize(t_list *lst);

/*
 * Gets the last node in the list.
 * @param[in] lst Pointer to a node in the list.
 * @returns Pointer to the last node in the list.
 */
t_list				*ft_lstlast(t_list *lst);

/*
 * Gets the first node in the list.
 * @param[in] lst Pointer to a node in the list.
 * @returns Pointer to the first node in the list.
 */
t_list				*ft_lstfirst(t_list *lst);

/* Search a node inside a list and returns if cmp(node->content,
 *  data_ref) returns 0.
 * @param[in] lst Memory address of the list to search .
 * @param[in] data_ref Value to compare to the content by cmp.
 *   if cmp does not need a seconds value can be set as NULL.
 * @param[in] cmp Function used to compare the content in the nodes.
 * @returns The first node that matches with the cmp function.
 */
t_list				*ft_lstchr(t_list *lst, void *data_ref, int (*cmp)(void *,
							void *));

/* Search a node inside a list from the end and returns if cmp(node->content,
 *  data_ref) returns 0.
 * @param[in] lst Memory address of the list to search.
 * @param[in] data_ref Value to compare to the content by cmp.
 *   if cmp does not need a seconds value can be set as NULL.
 * @param[in] cmp Function used to compare the content in the nodes.
 * @returns The last node that matches with the cmp function.
 */
t_list				*ft_lstrchr(t_list *lst, void *data_ref, int (*cmp)(void *,
							void *));

/*
 * Frees from memory a especific node.
 * @param[in] lst Node of the list to free.
 * @param[in] del Function to free the content of the list,
 *   unless it uses complex structures free() should suffice.
 */
void				ft_lstdelone(t_list *lst, void (*del)(void *));

/*
 * Frees the list and sets the start to NULL.
 * @param[in] lst Memory address of the first node of the list.
 * @param[in] del Function to free the content of the list,
 *   unless it uses complex structures free() should suffice.
 */
void				ft_lstclear(t_list **lst, void (*del)(void *));

/*
 * Applies the provided function to the content of every node in the list.
 * @param[in] *lst Pointer to a node in the list to apply to the contents.
 * @param[in] (*f) Funtion to use on every content.
 */
void				ft_lstiter(t_list *lst, void (*f)(void *));

/*
 * Creates a new list with a function porvided applied to it and using
 *   a function provided to clean it from memory if an error occurrs.
 * @param[in] lst List to use as source for the new one.
 * @param[in] (*f) function to create the content of the new list.
 * @param[in] (*del) function to clean the list.
 * @returns Pointer to the start of the new list.
 */
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

/*
 * Removes all connections of a node from a list.
 * @param[in] lst List where the node is located.
 * @param[in] node Node to detach from the list.
 * @returns Pointer to the isolated node.
 */
t_list				*ft_lstdetach(t_list **lst, t_list *node);

//= GET NEXT LINE =//

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/*
 * Gets the next line from a file.
 * @param[in] fd File descriptor of the file to read from.
 * @returns String of characters in the file.
 */
char				*get_next_line(int fd);

//= DEPRECATED, DO NOT USE =//

#endif

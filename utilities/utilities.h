/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:37:05 by aaslan            #+#    #+#             */
/*   Updated: 2023/01/04 00:43:26 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITIES_H
# define UTILITIES_H

# include <unistd.h>
# include <signal.h>

/**
 * @brief Verilen karakteri basar.
 *
 * @param c Basılacak karakter
 */
void	ft_print_char(char c);

/**
 * @brief Verilen string'i basar.
 *
 * @param string Basılacak string
 */
void	ft_print_string(const char *string);

/**
 * @brief Verilen integer değeri basar.
 *
 * @param number Basılacak sayı
 * @return int ==> Basılan karakter sayısı
 */
void	ft_print_integer(int number);

/**
 * @brief Verilen string'i intager'a çevirir ve geriye döner.
 *
 * String'e en başından itibaren tek tek karakter olarak bakar.
 * Karakter, ASCII tablosuna göre 9-13 arasında ise veya boşluksa hepsini atlar.
 * Rakamdan önce harf varsa 0 döner.
 * Rakamdan önce 1 den fazla + veya - işareti varsa 0 döner.
 * Rakamdan önce 1 tane + varsa sorun yok, 1 tane - varsa sayıyı negatif yapar.
 * Sayı, ilk rakam ile başlar ve rakam dışında ki bir karaktere kadar devam eder.
 * Rakam dışında bir şey ile karşılaşana kadar bulduğu sayıyı geriye döner.
 *
 * @param nptr Intager'a çevilecek olan string
 * @return int ==> Elde edilen intager değer
 */
int		ft_atoi(const char *nptr);

/**
 * @brief s pointer'ı içerisinde c parametresiyle gelen karakteri arar.
 * Karakteri bulduğunda geriye karakterin adresini döner.
 *
 * Eğer c parametresi ile gelen karakter '\0' ise
 * s'nin son index adresini geriye döner.
 * Eğer karakter bulunamazsa NULL döner.
 *
 * @param s Karakterin aranacağı pointer
 * @param c Aranan karakter
 * @return char* ==> s pointer'ı içerisinde ki c'nin adresi
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief Gelen string'in sadece rakamlardan oluşup oluşmadığına bakar.
 *
 * @param string Kontrol edilecek olan string ifade
 * @return int ==> 1 (true) veya 0 (false)
 */
int		ft_not_numeric(char *string);

#endif

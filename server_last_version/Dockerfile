# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcraster <kcraster@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/17 13:53:16 by kcraster          #+#    #+#              #
#    Updated: 2021/02/17 16:38:07 by kcraster         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

RUN apt-get update && \
    apt-get -y upgrade && \
    apt-get -y install wget && \
    apt-get -y install unzip && \
    apt-get -y install openssl && \
    apt-get -y install nginx && \
    apt-get -y install mariadb-server && \
    apt-get -y install php php-fpm php-mysql

RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-all-languages.zip && \
    unzip phpMyAdmin-5.0.4-all-languages.zip && \
    mv phpMyAdmin-5.0.4-all-languages /var/www/html/phpmyadmin && \
    rm -rf phpMyAdmin-5.0.4-all-languages

RUN wget https://ru.wordpress.org/latest-ru_RU.zip && \
    unzip latest-ru_RU.zip && \
    mv wordpress /var/www/html && \
    rm -rf latest-ru_RU.zip

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -out /etc/ssl/certs/localhost.crt \
	-keyout /etc/ssl/certs/localhost.key \
    -subj '/C=RU/ST=Kazan/L=Kazan/O=shcool21/OU=21/CN=tarampararam'

COPY /srcs/server.sh ./ 
COPY /srcs/config.inc.php /var/www/html/phpmyadmin
COPY /srcs/wp-config.php /var/www/html/wordpress
COPY /srcs/default.conf /etc/nginx/sites-available/localhost

CMD bash server.sh
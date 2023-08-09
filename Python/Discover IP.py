import socket as s

host = input('Digite o nome do host: ')

ip = s.gethostbyname(host)

print(f'O IP do Host {host} é {ip}')
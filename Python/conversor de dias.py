dias = int(input("dias:"))
horas = int(input("horas:"))
minutos = int(input("minutos:"))
segundos = int(input("segundos:"))
# um minuto tem 60 segundos 
# uma hora tem 3600 (60 * 60) segundos
# um dia tem 24 horas, logo 24 * 3600 segundos 
total_em_segundos = dias * 24 * 3600 + horas * 3600 + minutos * 60 + segundos
print( "convertido em segundos é igual a %10d segundos." % total_em_segundos)

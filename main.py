import math

def main():
    g = 9.81

    caudal = float (input("Caudal [m3/s]: "))
    longitud = float (input("Longitud [m]: "))
    rugosidad = float (input("Rugosidad absoluta [m]: "))
    headLoss = float (input("Pérdida admisible de cabeza [m]: "))
    viscosidad = float (input("Viscosidad [kg/m·s]: "))
    densidad = float (input("Densidad [kg/m3]: "))
    f_i = 4e-1
    a = 8 * (caudal ** 2) * longitud / (headLoss * g * math.pi ** 2)
    reConst = 4 * caudal / (math.pi * (viscosidad / densidad))
    while 1:
        fifthroot = (a*f_i)**(1/5)
        print("Diámetro: ", fifthroot)
        print("Reynolds: ", reConst /fifthroot)
        print("Rugosidad: ", rugosidad / fifthroot)
        if ((reConst / fifthroot) < 2000):
            if ((f_i - 64 / (reConst / fifthroot)) < 0.0001):
                if ((64 / (reConst / fifthroot)) - f_i < 0.0001):
                    print("Diámetro final: ", fifthroot," metros")
                    return 0
            f_i = 64 / (reConst/fifthroot)
            print ("Se asignó f_i según régimen laminar")
        else:
            f_i = float(input("¿f_i+1?: "))
        if (f_i <= 0.0):
            break
    return 0

main()

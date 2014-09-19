from tkinter import *
tk = Tk()
frame = Frame(tk)

canvas = Canvas(frame, width=1200, height=600)
canvas.pack()
canvas.create_line(20, 20, 20, 580)
canvas.create_line(20, 580, 1180, 580)

abscise = canvas.create_text(1150, 550, width=500)
canvas.itemconfig(abscise, text="Percee")

ordonnee = canvas.create_text(50, 10, width=500)
canvas.itemconfig(ordonnee, text="Victoire")

text = canvas.create_text(20 + 1.48 * 200, 590, width=50)
canvas.itemconfig(text, text="1,5")

for i in range(0, 6):
    text = canvas.create_text(45, 580 - i * 100, width=500)
    canvas.create_line(20, 580 - i * 100, 30, 580 - i * 100)
    texte = str(300 + i * 50)
    canvas.itemconfig(text, text=texte)

for i in range(0, 6):
    canvas.create_line(20 + i * 200, 580, 20 + i * 200, 570)
    text = canvas.create_text(20 + i * 200, 590, width=50)
    texte = str(i)
    canvas.itemconfig(text, text=texte)

fichier = open("heuristique.txt", "r")

for i in range(0, 528):
    # print(i)
    string = fichier.readline()
    armeeA = float(string[28:36])
    string = fichier.readline()
    string = fichier.readline()
    victoireA = int(string[4:8])

    canvas.create_line(armeeA * 200 + 20 - 3, 1180 - victoireA *
                       2 - 3, armeeA * 200 + 20 + 2, 1180 - victoireA * 2 + 3,)
    canvas.create_line(armeeA * 200 + 20 - 3, 1180 - victoireA *
                       2 + 3, armeeA * 200 + 20 + 3, 1180 - victoireA * 2 - 3,)
    string = fichier.readline()
    string = fichier.readline()
    string = fichier.readline()


# canvas.create_bitmap(armeeA*100,victoireA)

frame.pack()
frame.mainloop()

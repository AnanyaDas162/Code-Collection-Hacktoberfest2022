import random
import tkinter

stats = []


def get_winner(call):
    if random.random() <= (1 / 2):
        throw = "head"
    else:
        throw = "tail"

    if (throw == "head" and call == "head") or (throw == "tail" and call == "tail"):
        stats.append('W')
        result = "You won!"
    else:
        stats.append('L')
        result = "You lost!"

    global output
    output.config(text="Computer did: " + throw + "\n" + result)


def pass_h():
    get_winner("head")


def pass_t():
    get_winner("tail")


window = tkinter.Tk()

head = tkinter.Button(window, text="head",
                          bg="#ff9999", padx=10, pady=5, command=pass_h, width=20)
tail = tkinter.Button(window, text="tail", bg="#80ff80",
                      padx=10, pady=5, command=pass_t, width=20)
output = tkinter.Label(window, width=20, fg="red", text="What's your call?")

head.pack(side="left")
tail.pack(side="left")
output.pack(side="right")
window.mainloop()

for i in stats:
    print(i, end=" ")
if stats.count('L') > stats.count('W'):
    result = "\nYou loose the series."
elif stats.count('L') == stats.count('W'):
    result = "\nSeries ended in a draw."
else:
    result = "\nYou win the series."

print(result)
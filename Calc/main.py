import tkinter as tk

def on_button_click(event):
    text = event.widget.cget("text")

    if text == "=":
        try:
            result = str(eval(screen.get()))
            screen.set(result)
        except Exception as e:
            screen.set("Error")
    elif text == "C":
        screen.set("")
    else:
        screen.set(screen.get() + text)

root = tk.Tk()
root.geometry("400x600")
root.title("Calculator")

screen = tk.StringVar()
entry = tk.Entry(root, textvar=screen, font="lucida 30 bold")
entry.pack(fill=tk.X, ipadx=8, padx=10, pady=10, ipady=8)

frame = tk.Frame(root)
frame.pack()

buttons = [
    '7', '8', '9', '/',
    '4', '5', '6', '*',
    '1', '2', '3', '-',
    '0', 'C', '=', '+'
]

i = 0
for button in buttons:
    button_frame = tk.Button(frame, text=button, font="lucida 20 bold", padx=20, pady=20)
    button_frame.grid(row=i // 4, column=i % 4)
    button_frame.bind("<Button-1>", on_button_click)
    i += 1

root.mainloop()

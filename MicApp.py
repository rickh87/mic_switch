import tkinter as tk

root = tk.Tk()

v = tk.IntVar()

tk.Label(root, 
        text="""Select Mic/TNC:""",
        justify = tk.LEFT,
        padx = 20).pack()
tk.Radiobutton(root, 
              text="Mic",
              padx = 20, 
              variable=v, 
              value=1).pack(anchor=tk.W)
tk.Radiobutton(root, 
              text="TNV",
              padx = 20, 
              variable=v, 
              value=2).pack(anchor=tk.W)

root.mainloop()
from PIL import Image

# gera lista
origem = open("bytes.txt", "r")
byte = []
for i in range(1, 4435656):
    byte.append(int(origem.readline()))

#gera imagem

WIDTH, HEIGHT = 1215, 1215
FILENAME = ("resultado.png", "PNG")#cria o png

pillow_obj = Image.new("RGB", (WIDTH, HEIGHT))#define o tamanho e a entrada como RGB
pixel_set = pillow_obj.load()

a = 0
b = 1
c = 2
for row in range(HEIGHT):
    for col in range(WIDTH):
        color = (byte[a], byte[a], byte[c])
        a = a + 3
        b = b + 3
        c = c + 3
        pixel_set[col, row] = color
        

pillow_obj.save(*FILENAME)

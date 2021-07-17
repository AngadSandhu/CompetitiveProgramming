characters = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, ' ']#list(string.ascii_uppercase)+list(range(0,10))+[' ']

map_char = {}
char_map = {}
for idx,i in enumerate(characters):
    map_char[i]= idx
    char_map[idx] = i


def text_to_vector(texto,map_char,split):
    vectors = []
    size = len(texto)

    if (size%split) !=0 or size ==0:
        texto_new = texto + [' ']*(split-size%split)
    else:
        texto_new = texto
    #print(texto_new)
    for i in range(len(texto_new)//split):
        vector = [map_char[texto_new[i]] for i in range(i*split,(i+1)*split)]
        vectors.append(vector)
    return vectors

def matrix_map(vectors,matrix):
    ans = []
    for vector in vectors:
        new_vector = []
        for i in range(len(matrix)):
            suma = 0       
            for j in range(len(vector)):
                suma += vector[j]*matrix[i][j]%37
            new_vector.append(suma%37)
        ans.append(new_vector)
    return ans

def vector_to_text(vectors,char_map):
    ans = ''
    for vector in vectors:
        aux = [str(char_map[element]) for element in vector]
        ans+=''.join(aux)
    return ans


n = int(input())

matrix = []

for i in range(n):
    aux = list(map(int,input().split()))
    matrix.append(aux)

#print(matrix)
texto = list(input())
#print(texto)
vectors = text_to_vector(texto,map_char,n)
#print(vectors)
vectors = matrix_map(vectors,matrix)
#print(vectors)
new_text = vector_to_text(vectors,char_map)
print(new_text)

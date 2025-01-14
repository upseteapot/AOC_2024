
def has_word(content, word, x_0, y_0, dx, dy) 
  x = x_0
  y = y_0
  rows = content.length
  columns = content[0].length
  for i in 0...word.length do
    if x < 0 or x >= columns or y < 0 or y >= rows
      return 0 
    end
    if content[y][x] != word[i]
      return 0 
    end 
    x += dx
    y += dy
  end
  return 1 
end

content = File.readlines("input")
rows = content.length
columns = content[0].length


word = "XMAS"
word_count = 0

for i in 0...rows do
  for j in 0...columns do
    word_count += has_word(content, word, j, i, 0, 1) + 
      has_word(content, word, j, i, 1, 1) +  
      has_word(content, word, j, i, 1, 0) +  
      has_word(content, word, j, i, 1, -1) +  
      has_word(content, word, j, i, 0, -1) +  
      has_word(content, word, j, i, -1, -1) +  
      has_word(content, word, j, i, -1, 0) +  
      has_word(content, word, j, i, -1, 1) 
  end
end 

puts word_count 


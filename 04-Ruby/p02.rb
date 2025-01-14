content = File.readlines("input")
rows = content.length
columns = content[0].length

x_mas_count = 0

for i in 1...rows-1 do
  for j in 1...columns-1 do
    if ((content[i][j] == 'A') and 
        ((content[i-1][j-1] == 'M' and content[i+1][j+1] == 'S') or (content[i-1][j-1] == 'S' and content[i+1][j+1] == 'M')) and
        ((content[i-1][j+1] == 'M' and content[i+1][j-1] == 'S') or (content[i-1][j+1] == 'S' and content[i+1][j-1] == 'M')))
      x_mas_count += 1
    end
  end
end 

puts x_mas_count


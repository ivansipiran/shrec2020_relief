function saveMatrix(filename, matrix)

for i = 1:size(matrix, 1)
    matrix(i,i) = 0;
end

dlmwrite(filename, matrix, 'delimiter', ' ', 'precision', '%.6f');
function runScriptPatterns(folder)
addpath('./tools/');
numModels = 220;

R = 0.3;
S = 0.4;
Nm = 10;

for i = 1 : numModels
    basename = num2str(i);
    cad = sprintf('Computing signature of model %s\n', basename);
    disp(cad);
    desc = importdata([folder '/' basename '.desc']);
    
    numDesc = size(desc, 1);
    descNew =[];
    for j = 1 : numDesc
        descNew = [descNew; desc(j,:)/norm(desc(j,:))];
    end
    
    [C, W, I] = adaptiveClustering(descNew, R, S, Nm, 10, 1);
    SS{i}.name = basename;
    SS{i}.clusters = C;
    SS{i}.weights = W;
    disp(size(C));
end

%% Computation of the dissimilarity matrix
opt.alpha = 0.9;
opt.distance = 'L2';
opt.function = 'exp';

disp('Computing dissimalirity matrix');
diss = computeDissimilarityMatrixSQFD(SS, opt);
saveMatrix([folder '/test.matrix'], diss);
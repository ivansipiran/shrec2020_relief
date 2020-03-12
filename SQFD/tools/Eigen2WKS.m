function WKS = Eigen2WKS(evals, evecs)

num_vertices = size(evecs, 1);
N = 100; % number of evaluations of WKS
wks_variance = 6; % variance of the WKS gaussian (wih respect to the 
% difference of the two first eigenvalues). For easy or precision tasks 
% (eg. matching with only isometric deformations) you can take it smaller
PHI = evecs;
E = evals;
%E = diag(E);
E=abs(real(E));
[E,idx] = sort(E);
PHI = PHI(:,idx);
PHI=real(PHI);

fprintf('done. \n');

%% compute WKS 

fprintf('Computing WKS...\n');

WKS=zeros(num_vertices,N);

log_E=log(max(abs(E),1e-6))';
e=linspace(log_E(2),(max(log_E))/1.02,N);  
sigma=(e(2)-e(1))*wks_variance;

C = zeros(1,N); %weights used for the normalization of f_E

for i = 1:N
    WKS(:,i) = sum(PHI.^2.*...
        repmat( exp((-(e(i) - log_E).^2) ./ (2*sigma.^2)),num_vertices,1),2);
    C(i) = sum(exp((-(e(i)-log_E).^2)/(2*sigma.^2)));
end

% normalize WKS
WKS(:,:) = WKS(:,:)./repmat(C,num_vertices,1);

%fprintf('done. \n');
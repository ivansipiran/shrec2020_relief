function [evecs, evals, A] = off2spectrum(filename, opt)

if nargin < 1
    error('Too few input arguments');	 
elseif nargin < 2
    opt.hs = 2;
	opt.rho = 3;
	opt.htype = 'ddr';
	opt.dtype = 'euclidean';

elseif nargin < 3
	opt.hs = 2;
	opt.rho = 3;
	opt.htype = 'ddr';
	opt.dtype = 'euclidean';
end
opt=parse_opt(opt);

if opt.hs <= 0 | opt.rho <= 0
	error('Invalid values in opt');
end

[W,A, h] = symmshlp_matrix(filename, opt);
Am = sparse([1:length(A)], [1:length(A)], A);

nev = min(300, length(A));

[evecs, evals] = eigs(W, Am, nev, -1e-5);
evals = diag(evals);

% Parsing Option.
function option = parse_opt(opt)
option = opt;
option_names = {'hs', 'rho', 'htype', 'dtype'};
if ~isfield(option,'hs'),
	option = setfield(option,'hs',2);
end
if ~isfield(option,'rho'),
	option = setfield(option,'rho', 3);
end

if ~isfield(option,'htype'),
	option = setfield(option,'htype', 'ddr');
end

if ~isfield(option,'dtype'),
	option = setfield(option,'dtype', 'euclidean');
end
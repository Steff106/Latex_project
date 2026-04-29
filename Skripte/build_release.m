%% Wichtig zu wissen!
% Ab Matlab 2023 kann die Datentyp Benennung für die Autocode Generierung
% angepasst werden, damit diese direkt mit der Firmware übereinstimmt.
% https://de.mathworks.com/help/ecoder/ref/datatypereplacement.html

%% 
% Clear command window
clc
% close all files
fclose('all');
% Clear work folder and remove old build artefacts first
if exist('slprj','dir')
    rmdir ('slprj', 's');
end
if exist([bdroot '_ert_rtw'], 'dir')
    rmdir ([bdroot '_ert_rtw'], 's');
end
if exist(bdroot,'dir')
    rmdir (bdroot, 's');
end
% create output directory
mkdir (bdroot);
delete *.slxc

%% build section
fprintf('\n\n');
fprintf('----------------------------------------\n');
fprintf(' Code-Generation --> CPS_Data-structure \n');
fprintf('----------------------------------------\n');
% Disable Verbose build mode
set_param(bdroot,'RTWVerbose',false);
% Build the model
rtwbuild(bdroot, 'generateCodeOnly', true);
% Enable Verbose build mode
set_param(bdroot,'RTWVerbose',true);

%% PostProcessing: generate CPS-fragment and rework source files
fprintf('\n\n');
fprintf('--------------------------------------------------\n');
fprintf(' Code-Generation --> CPS_Fragment / Postprocessing \n');
fprintf('--------------------------------------------------\n');
run create_A2L_fragment.m
copyfile('A2L_Fragment.c',bdroot);
delete 'A2L_Fragment.c'
run create_CPS_fragment.m
copyfile('CPS_Fragment.c',bdroot);
delete 'CPS_Fragment.c'
% Call ASAP2Creator to create A2L-Template based on ASAP2_Fragment
copyfile ../../000_Tools/002_A2L/ASAP2_Creator/ASAP2Creator.ini
copyfile ../../000_Tools/002_A2L/ASAP2_Creator/Master.a2l
copyfile ../../000_Tools/002_A2L/ASAP2_Creator/ASAP2Merger.ini
copyfile ../../000_Tools/002_A2L/ASAP2_Creator/Interface.a2l
system('ASAP2Creator');
system('ASAP2Merger -PASAP2Merger.ini -SModelbased_playground_Template.a2l -MInterface.a2l -OModelbased_playground_Template.a2l');
delete ASAP2Creator.ini Master.a2l ASAP2Merger.ini Interface.a2l
% Definitions
% define build directory
build_dir = [bdroot '_ert_rtw\'];
% define ignored files
% ignore_files_h = [strcat(bdroot,"_types.h"), strcat(bdroot,"_private.h"), "Product_parameter.h","rtmodel.h", "rtwtypes.h"];
ignore_files_h = ["Product_parameter.h","rtmodel.h", "rtwtypes.h"];
ignore_files_c = "Product_parameter.c";
% get all auto generated .h and .c files
files_h = dir([build_dir '*.h']);
files_c = dir([build_dir '*.c']);
% get all important files and replace Embedded Coder header file by ZUSE header file with same content
for i = length(files_h):-1:1
    if sum(ismember(ignore_files_h, files_h(i).name)) > 0
        files_h(i) = [];
    else
        find_replace([build_dir files_h(i).name],'#include "rtwtypes.h"','#include <stdint.h>','#include <stdbool.h>');
        copyfile('temp.c', [bdroot '\' files_h(i).name]);
        delete 'temp.c'
    end
end
for i = length(files_c):-1:1
    if sum(ismember(ignore_files_c, files_c(i).name)) > 0
        files_c(i) = [];
    else
        find_replace([build_dir files_c(i).name],'#include "rtwtypes.h"','#include <stdint.h>','#include <stdbool.h>');
        copyfile('temp.c', [bdroot '\' files_c(i).name]);
        delete 'temp.c'
    end
end

%% CMakeList
fprintf('\n\n');
fprintf('-------------------------------------\n');
fprintf(' for CMakeList in alphabetical order \n');
fprintf('-------------------------------------\n');
ls = {};
for i = 1:1:length(files_c)
    ls{end+1} = files_c(i).name;
end

for i = 1:1:length(files_h)
    ls{end+1} = files_h(i).name;
end
ls{end+1} = 'Playground.c';
ls{end+1} = 'Playground.h';
ls = sort(ls);
for i = 1:1:length(ls)
    disp(ls(i))
    %disp('/n')
end

%% Finished
fprintf('\n\n');
fprintf('--------------------------\n');
fprintf(' Code-Generation finished \n');
fprintf('--------------------------\n');

%% Functions
function find_replace(file, old_h, int_h, bool_h)
    fidi = fopen(file,'r');
    fido = fopen('temp.c','w');
    try
        while ~feof(fidi)
          l = fgetl(fidi);   % read line
          if contains(l,old_h) 
              l = replace(l, old_h, int_h); % modify header line
              fprintf(fido,'%s\n',l);  % write new line with int header
              fprintf(fido,'%s\n',bool_h);  % write extra bool header
          else
              l = strrep(l,'float32_t','float'); % if present replace old datatype with new (until Matlab 2023)
              l = strrep(l,'float64_t','double'); % if present replace old datatype with new (until Matlab 2023)
              l = strrep(l,'bool_t','bool'); % if present replace old datatype with new (until Matlab 2023)
              fprintf(fido,'%s\n',l);  % write new line
          end
        end
    catch
        fclose(fido);
    end
    fclose(fidi);
    fclose(fido);
end
function varargout = bintodec(varargin)
% BINTODEC MATLAB code for bintodec.fig
%      BINTODEC, by itself, creates a new BINTODEC or raises the existing
%      singleton*.
%
%      H = BINTODEC returns the handle to a new BINTODEC or the handle to
%      the existing singleton*.
%
%      BINTODEC('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in BINTODEC.M with the given input arguments.
%
%      BINTODEC('Property','Value',...) creates a new BINTODEC or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before bintodec_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to bintodec_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help bintodec

% Last Modified by GUIDE v2.5 10-Apr-2019 16:46:52

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @bintodec_OpeningFcn, ...
                   'gui_OutputFcn',  @bintodec_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before bintodec is made visible.
function bintodec_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to bintodec (see VARARGIN)

% Choose default command line output for bintodec
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes bintodec wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = bintodec_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;



function enterval_Callback(hObject, eventdata, handles)
% hObject    handle to enterval (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of enterval as text
%        str2double(get(hObject,'String')) returns contents of enterval as a double


% --- Executes during object creation, after setting all properties.
function enterval_CreateFcn(hObject, eventdata, handles)
% hObject    handle to enterval (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in convert.
function convert_Callback(hObject, eventdata, handles)
% hObject    handle to convert (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
num = str2double(get(handles.enterval,'string'));
vect = zeros(1);
i = 1;
while num > 0
   rem = mod(num,10);
   vect(i) = rem;
   i = i+1;
   num = (num-rem)/10;
end
bin = 0;
for i = 1:length(vect)
    if vect(i) == 1
        bin = bin + power(2,i-1);
    end
end
set(handles.enterval,'string',bin);

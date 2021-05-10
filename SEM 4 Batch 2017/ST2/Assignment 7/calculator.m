function varargout = calculator(varargin)
% CALCULATOR MATLAB code for calculator.fig
%      CALCULATOR, by itself, creates a new CALCULATOR or raises the existing
%      singleton*.
%
%      H = CALCULATOR returns the handle to a new CALCULATOR or the handle to
%      the existing singleton*.
%
%      CALCULATOR('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in CALCULATOR.M with the given input arguments.
%
%      CALCULATOR('Property','Value',...) creates a new CALCULATOR or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before calculator_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to calculator_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help calculator

% Last Modified by GUIDE v2.5 27-Mar-2019 17:34:10

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @calculator_OpeningFcn, ...
                   'gui_OutputFcn',  @calculator_OutputFcn, ...
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


% --- Executes just before calculator is made visible.
function calculator_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to calculator (see VARARGIN)

% Choose default command line output for calculator
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes calculator wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = calculator_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in display.
%function display_Callback(hObject, eventdata, handles)
% hObject    handle to display (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes during object creation, after setting all properties.
%function display_CreateFcn(hObject, eventdata, handles)
% hObject    handle to display (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called


% --- Executes on button press in Number2.
function Number2_Callback(hObject, eventdata, handles)
% hObject    handle to Number2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
a = get(hObject,'string');
b = get(handles.display,'string');
c = [b a];
set(handles.display,'string',c);

% --- Executes on button press in Number3.
function Number3_Callback(hObject, eventdata, handles)
% hObject    handle to Number3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
a = get(hObject,'string');
b = get(handles.display,'string');
c = [b a];
set(handles.display,'string',c);

% --- Executes on button press in Number4.
function Number4_Callback(hObject, eventdata, handles)
% hObject    handle to Number4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
a = get(hObject,'string');
b = get(handles.display,'string');
c = [b a];
set(handles.display,'string',c);

% --- Executes on button press in Number5.
function Number5_Callback(hObject, eventdata, handles)
% hObject    handle to Number5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
a = get(hObject,'string');
b = get(handles.display,'string');
c = [b a];
set(handles.display,'string',c);

% --- Executes on button press in Number6.
function Number6_Callback(hObject, eventdata, handles)
% hObject    handle to Number6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
a = get(hObject,'string');
b = get(handles.display,'string');
c = [b a];
set(handles.display,'string',c);

% --- Executes on button press in Number7.
function Number7_Callback(hObject, eventdata, handles)
% hObject    handle to Number7 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
a = get(hObject,'string');
b = get(handles.display,'string');
c = [b a];
set(handles.display,'string',c);

% --- Executes on button press in Number8.
function Number8_Callback(hObject, eventdata, handles)
% hObject    handle to Number8 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
a = get(hObject,'string');
b = get(handles.display,'string');
c = [b a];
set(handles.display,'string',c);

% --- Executes on button press in Number9.
function Number9_Callback(hObject, eventdata, handles)
% hObject    handle to Number9 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
a = get(hObject,'string');
b = get(handles.display,'string');
c = [b a];
set(handles.display,'string',c);

% --- Executes on button press in Number0.
function Number0_Callback(hObject, eventdata, handles)
% hObject    handle to Number0 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
a = get(hObject,'string');
b = get(handles.display,'string');
c = [b a];
set(handles.display,'string',c);

% --- Executes on button press in Number1.
function Number1_Callback(hObject, eventdata, handles)
% hObject    handle to Number1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
a = get(hObject,'string');
b = get(handles.display,'string');
c = [b a];
set(handles.display,'string',c);

% --- Executes on button press in add.
function add_Callback(hObject, eventdata, handles)
% hObject    handle to add (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
a = get(hObject,'string');
b = get(handles.display,'string');
c = [b a];
set(handles.display,'string',c);

% --- Executes on button press in sub.
function sub_Callback(hObject, eventdata, handles)
% hObject    handle to sub (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
a = get(hObject,'string');
b = get(handles.display,'string');
c = [b a];
set(handles.display,'string',c);

% --- Executes on button press in mul.
function mul_Callback(hObject, eventdata, handles)
% hObject    handle to mul (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
a = get(hObject,'string');
b = get(handles.display,'string');
c = [b a];
set(handles.display,'string',c);

% --- Executes on button press in div.
function div_Callback(hObject, eventdata, handles)
% hObject    handle to div (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
a = get(hObject,'string');
b = get(handles.display,'string');
c = [b a];
set(handles.display,'string',c);

% --- Executes on button press in clear.
function clear_Callback(hObject, eventdata, handles)
% hObject    handle to clear (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set(handles.display,'string',[]);

% --- Executes on button press in equal.
function equal_Callback(hObject, eventdata, handles)
% hObject    handle to equal (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
a = get(handles.display,'string');
a1 = eval(a);
set(handles.display,'string',a1);


% --- Executes on button press in display.
function display_Callback(hObject, eventdata, handles)
% hObject    handle to display (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes during object creation, after setting all properties.
function display_CreateFcn(hObject, eventdata, handles)
% hObject    handle to display (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called


% --- Executes on button press in dot.
function dot_Callback(hObject, eventdata, handles)
% hObject    handle to dot (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
a = get(hObject,'string');
b = get(handles.display,'string');
c = [b a];
set(handles.display,'string',c);


% --- Executes on button press in power.
function power_Callback(hObject, eventdata, handles)
% hObject    handle to power (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
a = get(hObject,'string');
b = get(handles.display,'string');
c = [b a];
set(handles.display,'string',c);

% --- Executes on button press in bracketopen.
function bracketopen_Callback(hObject, eventdata, handles)
% hObject    handle to bracketopen (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
a = get(hObject,'string');
b = get(handles.display,'string');
c = [b a];
set(handles.display,'string',c);

% --- Executes on button press in bracketclose.
function bracketclose_Callback(hObject, eventdata, handles)
% hObject    handle to bracketclose (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
a = get(hObject,'string');
b = get(handles.display,'string');
c = [b a];
set(handles.display,'string',c);

% --- Executes on button press in PI.
function PI_Callback(hObject, eventdata, handles)
% hObject    handle to PI (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
a = get(hObject,'string');
b = get(handles.display,'string');
c = [b a];
set(handles.display,'string',c);


% --- Executes on button press in delete.
function delete_Callback(hObject, eventdata, handles)
% hObject    handle to delete (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
a = get(handles.display,'string');
len = length(a);
b = a(1:len-1);
set(handles.display,'string',b);

function varargout = graph(varargin)
% GRAPH MATLAB code for graph.fig
%      GRAPH, by itself, creates a new GRAPH or raises the existing
%      singleton*.
%
%      H = GRAPH returns the handle to a new GRAPH or the handle to
%      the existing singleton*.
%
%      GRAPH('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in GRAPH.M with the given input arguments.
%
%      GRAPH('Property','Value',...) creates a new GRAPH or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before graph_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to graph_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help graph

% Last Modified by GUIDE v2.5 02-Apr-2019 21:47:10

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @graph_OpeningFcn, ...
                   'gui_OutputFcn',  @graph_OutputFcn, ...
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

% --- Executes just before graph is made visible.
function graph_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to graph (see VARARGIN)

% Choose default command line output for graph
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% This sets up the initial plot - only do when we are invisible
% so window can get raised using graph.
if strcmp(get(hObject,'Visible'),'off')
    plot(rand(5));
end

% UIWAIT makes graph wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = graph_OutputFcn(hObject, eventdata, handles)
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;

% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
axes(handles.axes1);
cla;
% --------------------------------------------------------------------
function FileMenu_Callback(hObject, eventdata, handles)
% hObject    handle to FileMenu (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function OpenMenuItem_Callback(hObject, eventdata, handles)
% hObject    handle to OpenMenuItem (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
file = uigetfile('*.fig');
if ~isequal(file, 0)
    open(file);
end

% --------------------------------------------------------------------
function PrintMenuItem_Callback(hObject, eventdata, handles)
% hObject    handle to PrintMenuItem (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
printdlg(handles.figure1)

% --------------------------------------------------------------------
function CloseMenuItem_Callback(hObject, eventdata, handles)
% hObject    handle to CloseMenuItem (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
selection = questdlg(['Close ' get(handles.figure1,'Name') '?'],...
                     ['Close ' get(handles.figure1,'Name') '...'],...
                     'Yes','No','Yes');
if strcmp(selection,'No')
    return;
end

delete(handles.figure1)


% --- Executes on selection change in popupmenu1.
function popupmenu1_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenu1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = get(hObject,'String') returns popupmenu1 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenu1


% --- Executes during object creation, after setting all properties.
function popupmenu1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenu1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
     set(hObject,'BackgroundColor','white');
end

set(hObject, 'String', {'plot(rand(5))', 'plot(sin(1:0.01:25))', 'bar(1:.5:10)', 'plot(membrane)', 'surf(peaks)'});



function edity0_Callback(hObject, eventdata, handles)
% hObject    handle to edity0 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edity0 as text
%        str2double(get(hObject,'String')) returns contents of edity0 as a double


% --- Executes during object creation, after setting all properties.
function edity0_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edity0 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edity1_Callback(hObject, eventdata, handles)
% hObject    handle to edity1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edity1 as text
%        str2double(get(hObject,'String')) returns contents of edity1 as a double

% --- Executes during object creation, after setting all properties.
function edity1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edity1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function editx0_Callback(hObject, eventdata, handles)
% hObject    handle to editx0 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of editx0 as text
%        str2double(get(hObject,'String')) returns contents of editx0 as a double

% --- Executes during object creation, after setting all properties.
function editx0_CreateFcn(hObject, eventdata, handles)
% hObject    handle to editx0 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function editx1_Callback(hObject, eventdata, handles)
% hObject    handle to editx1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of editx1 as text
%        str2double(get(hObject,'String')) returns contents of editx1 as a double

% --- Executes during object creation, after setting all properties.
function editx1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to editx1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in sine.
function sine_Callback(hObject, eventdata, handles)
% hObject    handle to sine (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
axes(handles.axes1);
cla;
usery1 = str2double(get(handles.edity1,'String'));
usery0 = str2double(get(handles.edity0,'String'));
userx1 = str2double(get(handles.editx1,'String'));
userx0 = str2double(get(handles.editx0,'String'));
x =(-2*pi:0.1:2*pi);
plot(sin(x));
xlim([userx0 userx1]);
ylim([usery0 usery1]);

% --- Executes on button press in cosine.
function cosine_Callback(hObject, eventdata, handles)
% hObject    handle to cosine (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
axes(handles.axes1);
cla;
usery1 = str2double(get(handles.edity1,'String'));
usery0 = str2double(get(handles.edity0,'String'));
userx1 = str2double(get(handles.editx1,'String'));
userx0 = str2double(get(handles.editx0,'String'));
x =(-2*pi:0.1:2*pi);
plot(cos(x));
xlim([userx0 userx1]);
ylim([usery0 usery1]);

% --- Executes on button press in tan.
function tan_Callback(hObject, eventdata, handles)
% hObject    handle to tan (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
axes(handles.axes1);
cla;
usery1 = str2double(get(handles.edity1,'String'));
usery0 = str2double(get(handles.edity0,'String'));
userx1 = str2double(get(handles.editx1,'String'));
userx0 = str2double(get(handles.editx0,'String'));
x =(-2*pi:0.1:2*pi);
plot(tan(x));
xlim([userx0 userx1]);
ylim([usery0 usery1]);

% --- Executes on button press in cot.
function cot_Callback(hObject, eventdata, handles)
% hObject    handle to cot (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
axes(handles.axes1);
cla;
usery1 = str2double(get(handles.edity1,'String'));
usery0 = str2double(get(handles.edity0,'String'));
userx1 = str2double(get(handles.editx1,'String'));
userx0 = str2double(get(handles.editx0,'String'));
x =(-2*pi:0.1:2*pi);
plot(cot(x));
xlim([userx0 userx1]);
ylim([usery0 usery1]);

% --- Executes on button press in sec.
function sec_Callback(hObject, eventdata, handles)
% hObject    handle to sec (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
axes(handles.axes1);
cla;
usery1 = str2double(get(handles.edity1,'String'));
usery0 = str2double(get(handles.edity0,'String'));
userx1 = str2double(get(handles.editx1,'String'));
userx0 = str2double(get(handles.editx0,'String'));
x =(-2*pi:0.1:2*pi);
plot(sec(x));
xlim([userx0 userx1]);
ylim([usery0 usery1]);

% --- Executes on button press in cosec.
function cosec_Callback(hObject, eventdata, handles)
% hObject    handle to cosec (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
axes(handles.axes1);
cla;
usery1 = str2double(get(handles.edity1,'String'));
usery0 = str2double(get(handles.edity0,'String'));
userx1 = str2double(get(handles.editx1,'String'));
userx0 = str2double(get(handles.editx0,'String'));
x =(-2*pi:0.1:2*pi);
plot(csc(x));
xlim([userx0 userx1]);
ylim([usery0 usery1]);

from pydantic import BaseModel
from typing import Optional,List

class UserBase(BaseModel):
    roll:Optional[str]=None
    name:str
    username:str
    last_name: Optional[str]=None
    phone_number:int
    region:Optional[str]=None
    password:Optional[str]=None

class UserCreate(UserBase):
    pass

class UserUpdate(UserBase):
    id:int
    status:bool



class Token(BaseModel):
    access_token=str
    token=str

class TokenData(BaseModel):
    id: Optional[str] = None

class UserCurrent(BaseModel):
    roll: str
    name: str
    username:str
    last_name: str
    phone_number: int
    password: str
    region:str
    status: bool
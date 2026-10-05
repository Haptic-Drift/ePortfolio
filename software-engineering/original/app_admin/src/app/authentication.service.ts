import { Inject, Injectable } from '@angular/core';
import { BROWSER_STORAGE } from './storage';
import { User } from './models/user';
import { AuthResponse } from './models/auth-response';
import { TripDataService } from './trip-data.service';
import { Observable } from 'rxjs';

@Injectable({
  providedIn: 'root'
})
export class AuthenticationService {
  authResp: AuthResponse = new AuthResponse();

  constructor(
    @Inject(BROWSER_STORAGE) private storage: Storage,
    private tripDataService: TripDataService
  ) {}

  public saveToken(token: string): void {
    this.storage.setItem('travlr-token', token);
  }

  public getToken(): string {
    const token = this.storage.getItem('travlr-token');
    return token ? token : '';
  }

  public logout(): void {
    this.storage.removeItem('travlr-token');
  }

  public isLoggedIn(): boolean {
    const token = this.getToken();
    return token !== '';
  }

  public register(user: User, password: string): Observable<AuthResponse> {
    return this.tripDataService.register(user, password);
  }

  public login(user: User, password: string): Observable<AuthResponse> {
    return this.tripDataService.login(user, password);
  }
}